#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn testcase_1() {
        let words = ["This", "is", "an", "example", "of", "text", "justification."];
        let max_width = 16;
        let output : Vec<String> = [
            "This    is    an",
            "example  of text",
            "justification.  "
        ].iter().map(|s| s.to_string()).collect();
        assert_eq!(output, full_justify(&words, max_width));
    }

    #[test]
    fn testcase_2() {
        let words = ["What","must","be","acknowledgment","shall","be"];
        let max_width = 16;
        let output : Vec<String> = [
            "What   must   be",
            "acknowledgment  ",
            "shall be        "
        ].iter().map(|s| s.to_string()).collect();
        assert_eq!(output, full_justify(&words, max_width));
    }

    #[test]
    fn testcase_3() {
        let words = ["Science","is","what","we","understand","well","enough","to","explain","to","a",
            "computer.","Art","is","everything","else","we","do"];
        let max_width = 20;
        let output : Vec<String> = [
            "Science  is  what we",
            "understand      well",
            "enough to explain to",
            "a  computer.  Art is",
            "everything  else  we",
            "do                  "
        ].iter().map(|s| s.to_string()).collect();
        assert_eq!(output, full_justify(&words, max_width));
    }
}

pub fn full_justify(words: &[&str], max_width: i32) -> Vec<String> {
    let max_width = max_width as usize;
    let mut result = vec![];
    let mut words_in_line = vec![];
    let mut words_width = 0;

    for word in words {
        let new_width = words_width + word.len() + words_in_line.len();

        if new_width > max_width {
            result.push(fully_justify_line(&words_in_line, max_width));

            words_in_line.clear();
            words_width = 0;
        }

        words_width += word.len();
        words_in_line.push(word);
    }

    if words_in_line.len() > 0 {
        result.push(left_justify_line(&words_in_line, max_width));
    }

    result
}

fn fully_justify_line(words_in_line: &[&str], max_width: usize) -> String {
    let n = words_in_line.len();
    if n == 1 {
        return left_justify_line(words_in_line, max_width);
    }

    let char_count: usize = words_in_line.iter().map(|s| s.len()).sum();
    let total_space_count = max_width - char_count;
    let gap_count = n - 1;
    let base_space_count = total_space_count / gap_count;
    let extra_space_count = total_space_count % gap_count;

    let mut result = String::with_capacity(max_width);

    for (i, word) in words_in_line.iter().enumerate() {
        result.push_str(word);

        if i == gap_count {
            continue;
        }

        let space_count = base_space_count + if i < extra_space_count { 1 } else { 0 };
        for _ in 0..space_count {
            result.push(' ');
        }
    }

    result
}

fn left_justify_line(words_in_line: &[&str], max_width: usize) -> String {
    let mut result = String::with_capacity(max_width);

    for i in 0..words_in_line.len() {
        if i > 0 {
            result.push(' ');
        }
        result.push_str(words_in_line[i]);
    }

    while result.len() < max_width {
        result.push(' ');
    }

    result
}
