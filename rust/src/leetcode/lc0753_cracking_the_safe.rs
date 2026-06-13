#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn testcase_1() {
        let n = 1;
        let k = 2;
        let output = crack_safe(n, k);
        assert!(validate(&output, &mut String::new(), n, k));
    }

    #[test]
    fn testcase_2() {
        let n = 2;
        let k = 2;
        let output = crack_safe(n, k);
        assert!(validate(&output, &mut String::new(), n, k));
    }

    fn validate(value: &String, pass: &mut String, n: i32, k: i32) -> bool {
        if n == 0 {
            return value.contains(pass.as_str());
        }
        for i in 0..k as u8 {
            pass.push(char::from(b'0' + i));
            if !validate(value, pass, n - 1, k) {
                return false;
            }
            pass.pop();
        }
        true
    }
}

pub fn crack_safe(n: i32, k: i32) -> String {
    let n = n as usize;
    let k = k as usize;

    let count = k.pow(n as u32);

    let mut visited = vec![false; count];

    visited[0] = true;

    let base = k.pow(n as u32 - 1);

    let mut result = encode(0, n, k);

    dfs(0, &mut visited, &mut result, count - 1, k, base);

    result
}

fn dfs(node: usize, visited: &mut [bool], result: &mut String, remaining: usize, k: usize, base: usize) -> bool {
    if remaining == 0 {
        return true;
    }

    for i in 0..k {
        let next = (node % base) * k + i;

        if visited[next] {
            continue;
        }

        visited[next] = true;

        result.push(char::from(b'0' + i as u8));

        if dfs(next, visited, result, remaining - 1, k, base) {
            return true;
        }

        result.pop();
        visited[next] = false;
    }

    false
}

fn encode(mut val: usize, n: usize, k: usize) -> String {
    let mut chars = vec!['0'; n];

    for i in (0..n).rev() {
        chars[i] = char::from(b'0' + (val % k) as u8);
        val /= k;
    }

    chars.into_iter().collect()
}
