use std::collections::HashSet;

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn testcase_1() {
        let cards = vec![4,1,8,7];
        assert_eq!(true, judge_point24(cards));
    }

    #[test]
    fn testcase_2() {
        let cards = vec![1,2,1,2];
        assert_eq!(false, judge_point24(cards));
    }
}

pub fn judge_point24(cards: Vec<i32>) -> bool {
    let n = 1 << cards.len();

    let mut possible_results = vec![HashSet::new(); n];

    for (i, &card) in cards.iter().enumerate() {
        possible_results[1 << i].insert((card, 1));
    }

    for mask in 3..n {

        for submask in 1..mask {

            if mask & submask != submask {
                continue;
            }

            let complement = mask ^ submask;

            if complement < submask {
                continue;
            }

            let lhs = possible_results[submask].clone();
            let rhs = possible_results[complement].clone();

            for (a, b) in &lhs {
                for (c, d) in &rhs {

                    possible_results[mask].insert(normalise(a * d + c * b, b * d));
                    possible_results[mask].insert(normalise(a * d - c * b, b * d));
                    possible_results[mask].insert(normalise(c * b - a * d, b * d));
                    possible_results[mask].insert(normalise(a * c, b * d));

                    if *c != 0 {
                        possible_results[mask].insert(normalise(a * d, b * c));
                    }
                    if *a != 0 {
                        possible_results[mask].insert(normalise(c * b, d * a));
                    }
                }
            }
        }
    }

    possible_results[n - 1].contains(&(24, 1))
}

fn normalise(num: i32, den: i32) -> (i32, i32) {
    let factor = gcd(num.abs(), den.abs());

    if den > 0 {
        (num / factor, den / factor)
    } else {
        (-num / factor, -den / factor)
    }
}

fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}
