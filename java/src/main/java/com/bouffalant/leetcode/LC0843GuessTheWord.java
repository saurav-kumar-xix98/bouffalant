package com.bouffalant.leetcode;

import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class LC0843GuessTheWord {

    private static final int WORD_LENGTH = 6;
    private static final int MAX_GUESSES = 30;
    private static final int SCORE_RANGE = WORD_LENGTH + 1;

    public static void findSecretWord(String[] words, Master master) {
        int[][] scores = buildScoreMatrix(words);
        Set<Integer> candidates = new HashSet<>();
        for (int i = 0; i < words.length; ++i) {
            candidates.add(i);
        }

        for (int i = 0; i < MAX_GUESSES; ++i) {
            int guessIndex = selectBestCandidate(candidates, scores);
            int matchScore = master.guess(words[guessIndex]);
            if (matchScore == WORD_LENGTH) {
                return;
            }
            candidates = filterCandidates(candidates, scores, guessIndex, matchScore);
        }
    }

    private static Set<Integer> filterCandidates(Set<Integer> oldPossibleAnswers, int[][] scores, int guessIndex, int expectedScore) {
        return oldPossibleAnswers.stream()
                .filter(i -> scores[guessIndex][i] == expectedScore)
                .collect(Collectors.toSet());
    }

    private static int selectBestCandidate(Set<Integer> candidates, int[][] scores) {
        int bestIndex = 0;
        int[] bestDistribution = buildScoreDistribution(candidates, scores, 0);

        for (int i = 1; i < scores.length; ++i) {
            int[] distribution = buildScoreDistribution(candidates, scores, i);
            if (isBetterCandidate(i, distribution, bestIndex, bestDistribution, candidates)) {
                bestIndex = i;
                bestDistribution = distribution;
            }
        }

        return bestIndex;
    }

    private static boolean isBetterCandidate(int index, int[] current, int otherIndex, int[] other, Set<Integer> candidates) {
        for (int i = SCORE_RANGE - 1; i >= 0; --i) {
            if (current[i] < other[i]) {
                return true;
            }
            if (current[i] > other[i]) {
                return false;
            }
        }

        return candidates.contains(index) && !(candidates.contains(otherIndex));
    }

    private static int[] buildScoreDistribution(Set<Integer> candidates, int[][] scores, int index) {
        int[] distribution = new int[SCORE_RANGE];

        for (int candidate: candidates) {
            int score = scores[index][candidate];
            distribution[score]++;
        }

        Arrays.sort(distribution);

        return distribution;
    }

    private static int[][] buildScoreMatrix(String[] words) {
        int n = words.length;
        int[][] scores = new int[n][n];
        for (int i = 0; i < n; ++i) {
            scores[i][i] = WORD_LENGTH;
            for (int j = 0; j < i; ++j) {
                int score = computeMatchScore(words[i], words[j]);
                scores[i][j] = score;
                scores[j][i] = score;
            }
        }
        return scores;
    }

    private static int computeMatchScore(String word1, String word2) {
        int count = 0;
        for (int i = 0; i < WORD_LENGTH; ++i) {
            if (word1.charAt(i) == word2.charAt(i)) {
                count++;
            }
        }
        return count;
    }

    public static class Master {
        private final String secret;
        private final Set<String> words;
        private int allowedGuesses;
        private boolean guessed;

        public Master(String secret, String[] words, int allowedGuesses) {
            this.secret = secret;
            this.words = new HashSet<>(List.of(words));
            this.allowedGuesses = allowedGuesses;
            this.guessed = false;
        }

        public boolean isGuessed() {
            return guessed;
        }

        public int guess(String word) {
            if (allowedGuesses == 0) {
                return -1;
            }

            allowedGuesses--;

            if (!words.contains(word)) {
                return -1;
            }

            if (secret.equals(word)) {
                guessed = true;
                return WORD_LENGTH;
            }

            return computeMatchScore(secret, word);
        }
    }
}
