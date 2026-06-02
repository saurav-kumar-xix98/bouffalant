#include "leetcode/LC0843GuessTheWord.hpp"

#include <algorithm>
#include <numeric>
#include <ranges>

namespace {
    constexpr uint8_t WORD_LENGTH = 6;
    constexpr uint8_t SCORE_RANGE = WORD_LENGTH + 1;
    constexpr uint8_t MAX_GUESSES = 30;

    std::vector<std::vector<uint8_t>> buildScoreMatrix(const std::vector<std::string> &words);
    size_t findBestCandidate(const std::unordered_set<size_t> &candidates, const std::vector<std::vector<uint8_t>> &scoreMatrix);
    std::unordered_set<size_t> filterCandidates(const std::unordered_set<size_t> &candidates, const std::vector<uint8_t> &guessCandidateScores, int guessScore);
    uint8_t computeMatchCount(const std::string &s1, const std::string &s2);
}

void LC0843GuessTheWord::findSecretWord(const std::vector<std::string>& words, Master& master) {
    const auto scoreMatrix = buildScoreMatrix(words);
    auto candidates = std::views::iota(size_t{0}, words.size()) | std::ranges::to<std::unordered_set>();

    for (uint8_t i = 0; i < MAX_GUESSES; ++i) {
        const size_t candidate = findBestCandidate(candidates, scoreMatrix);

        const int score = master.guess(words[candidate]);
        if (score == WORD_LENGTH) {
            return;
        }

        candidates = filterCandidates(candidates, scoreMatrix[candidate], score);
    }
}

LC0843GuessTheWord::Master::Master(std::string secret, const std::vector<std::string>& words, const uint8_t allowed_guesses) :
        secret(std::move(secret)),
        words(words.begin(), words.end()),
        allowed_guesses(allowed_guesses),
        guessed(false) {}

bool LC0843GuessTheWord::Master::isGuessed() const {
    return guessed;
}

int LC0843GuessTheWord::Master::guess(const std::string& word) {
    if (allowed_guesses == 0) {
        return -1;
    }

    allowed_guesses--;

    if (!words.contains(word)) {
        return -1;
    }

    if (word == secret) {
        guessed = true;
        return WORD_LENGTH;
    }

    return computeMatchCount(secret, word);
}

namespace {
    uint8_t computeMatchCount(const std::string &s1, const std::string &s2) {
        uint8_t matchCount = 0;

        for (size_t i = 0; i < WORD_LENGTH; ++i) {
            if (s1[i] == s2[i])
                matchCount++;
        }

        return matchCount;
    }

    std::vector<std::vector<uint8_t>> buildScoreMatrix(const std::vector<std::string> &words) {
        const size_t N = words.size();

        std::vector scoreMatrix(N, std::vector(N, uint8_t{0}));

        for (size_t i = 0; i < N; ++i) {
            scoreMatrix[i][i] = WORD_LENGTH;

            for (size_t j = i + 1; j < N; ++j) {
                const int matchCount = computeMatchCount(words[i], words[j]);

                scoreMatrix[i][j] = matchCount;
                scoreMatrix[j][i] = matchCount;
            }
        }

        return scoreMatrix;
    }

    std::array<uint8_t, SCORE_RANGE> computePartitionProfile(const std::unordered_set<size_t> &candidates, const std::vector<uint8_t> &scores) {
        std::array<uint8_t, SCORE_RANGE> partitionProfile{};
        for (const auto candidate : candidates) {
            partitionProfile[scores[candidate]]++;
        }
        std::ranges::sort(partitionProfile, std::greater{});
        return partitionProfile;
    }

    bool isBetterPartitionProfile(const std::array<uint8_t, SCORE_RANGE>& currentDistribution, const std::array<uint8_t, SCORE_RANGE>& bestDistribution) {
        for (size_t i = 0; i < SCORE_RANGE; ++i) {
            if (currentDistribution[i] < bestDistribution[i]) {
                return true;
            }
            if (currentDistribution[i] > bestDistribution[i]) {
                return false;
            }
        }

        return false;
    }

    size_t findBestCandidate(const std::unordered_set<size_t> &candidates, const std::vector<std::vector<uint8_t>> &scoreMatrix) {
        if (candidates.size() == 1) {
            return *candidates.begin();
        }
        size_t bestIndex = 0;
        auto bestPartitionProfile = computePartitionProfile(candidates, scoreMatrix[bestIndex]);

        for (size_t i = 1; i < scoreMatrix.size(); ++i) {
            if (const auto partitionProfile = computePartitionProfile(candidates, scoreMatrix[i]);
                isBetterPartitionProfile(partitionProfile, bestPartitionProfile)) {
                bestIndex = i;
                bestPartitionProfile = partitionProfile;
            }
        }

        return bestIndex;
    }

    std::unordered_set<size_t> filterCandidates(const std::unordered_set<size_t> &candidates, const std::vector<uint8_t> &guessCandidateScores, const int guessScore) {
        return candidates |
            std::views::filter([&](const size_t candidate) { return guessCandidateScores[candidate] == guessScore; }) |
            std::ranges::to<std::unordered_set>();
    }
}
