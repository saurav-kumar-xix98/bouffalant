use std::collections::HashSet;

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn testcase_1() {
        let secret = "acckzz";
        let words = ["acckzz","ccbazz","eiowzz","abcczz"];
        let allowed_guesses = 10;
        let mut master = Master::new(&words, secret, allowed_guesses);
        find_secret_word(&words, &mut master);
        assert!(master.guessed());
    }

    #[test]
    fn testcase_2() {
        let secret = "hamada";
        let words = ["hamada","khaled"];
        let allowed_guesses = 10;
        let mut master = Master::new(&words, secret, allowed_guesses);
        find_secret_word(&words, &mut master);
        assert!(master.guessed());
    }
}

static WORD_LENGTH: usize = 6;
static SCORE_RANGE: usize = WORD_LENGTH + 1;
static MAX_GUESSES: i8 = 30;

pub fn find_secret_word(words: &[&str], master: &mut Master) {

    let score_matrix = build_score_matrix(words);
    let mut candidates: HashSet<usize> = (0..words.len()).collect();

    for _ in 0..MAX_GUESSES {
        let guess_index = find_best_candidate(&candidates, &score_matrix);

        let score = master.guess(words[guess_index]);
        if score == WORD_LENGTH as i8 {
            return;
        }

        candidates = filter_candidates(candidates, &score_matrix[guess_index], score);
    }
}

fn filter_candidates(candidates: HashSet<usize>, guess_candidate_scores: &Vec<i8>, guess_score: i8) -> HashSet<usize> {
    candidates.into_iter()
        .filter(|&candidate| { guess_candidate_scores[candidate] == guess_score })
        .collect()
}

fn find_best_candidate(candidates: &HashSet<usize>, score_matrix: &Vec<Vec<i8>>) -> usize {
    if candidates.len() == 1 {
        return candidates.iter().next().unwrap().clone();
    }

    let mut best_index = 0;
    let mut best_score_frequency = compute_score_frequency(candidates, &score_matrix[best_index]);

    for i in 1..score_matrix.len() {
        let score_frequency = compute_score_frequency(candidates, &score_matrix[i]);
        if is_better_score_frequency(score_frequency, best_score_frequency) {
            best_index = i;
            best_score_frequency = score_frequency;
        }
    }

    best_index
}

fn compute_score_frequency(candidates: &HashSet<usize>, score_matrix: &Vec<i8>) -> [usize; SCORE_RANGE] {
    let mut score_frequency = [0; SCORE_RANGE];

    for &candidate in candidates {
        score_frequency[score_matrix[candidate] as usize] += 1;
    }

    score_frequency.sort_by(|a, b| b.cmp(a));

    score_frequency
}

fn is_better_score_frequency(score_frequency1: [usize; SCORE_RANGE], score_frequency2: [usize; SCORE_RANGE]) -> bool {
    for i in 0..SCORE_RANGE {
        if score_frequency1[i] < score_frequency2[i] {
            return true;
        }
        if score_frequency1[i] > score_frequency2[i] {
            return false;
        }
    }

    false
}

fn build_score_matrix(words: &[&str]) -> Vec<Vec<i8>> {
    let mut score_matrix = vec![vec![0i8; words.len()]; words.len()];
    for i in 0..words.len() {
        score_matrix[i][i] = WORD_LENGTH as i8;
        for j in i + 1..words.len() {
            let match_score = compute_match_count(words[i], words[j]);
            score_matrix[i][j] = match_score;
            score_matrix[j][i] = match_score;
        }
    }
    score_matrix
}

fn compute_match_count(word1: &str, word2: &str) -> i8 {
    word1.chars().zip(word2.chars())
    .filter(|&(c1, c2)| c1 == c2)
    .count() as i8
}

pub struct Master {
    words: HashSet<String>,
    secret: String,
    allowed_guesses: u8,
    guessed: bool
}

impl Master {
    pub fn guess(&mut self, word: &str) -> i8 {
        if self.allowed_guesses == 0 {
            return -1;
        }

        self.allowed_guesses -= 1;

        if !self.words.contains(word) {
            return -1;
        }

        if word == self.secret {
            self.guessed = true;
            return WORD_LENGTH as i8;
        }

        compute_match_count(word, self.secret.as_str())
    }
}

#[cfg(test)]
impl Master {
    fn new(words: &[&str], secret: &str, allowed_guesses: u8) -> Self {
        Self {
            words: words.iter().map(|s| s.to_string()).collect(),
            secret: secret.to_string(),
            allowed_guesses,
            guessed: false,
        }
    }

    fn guessed(&self) -> bool {
        self.guessed
    }
}
