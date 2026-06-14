use std::collections::BTreeMap;
use std::ops::Bound::{Included, Unbounded};

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn testcase_1() {
        let arr = vec![10,13,12,14,15];
        assert_eq!(2, odd_even_jumps(arr));
    }

    #[test]
    fn testcase_2() {
        let arr = vec![2,3,1,1,4];
        assert_eq!(3, odd_even_jumps(arr));
    }

    #[test]
    fn testcase_3() {
        let arr = vec![5,1,3,4,2];
        assert_eq!(3, odd_even_jumps(arr));
    }
}

pub fn odd_even_jumps(arr: Vec<i32>) -> i32 {
    let n = arr.len();

    let mut odd_jump_possible = vec![false; n];
    let mut even_jump_possible = vec![false; n];

    odd_jump_possible[n - 1] = true;
    even_jump_possible[n - 1] = true;

    let mut values_seen = BTreeMap::new();
    values_seen.insert(arr[n - 1], n - 1);

    for i in (0..n - 1).rev() {
        if let Some((_, &idx)) = values_seen.range((Included(&arr[i]), Unbounded)).next() {
            odd_jump_possible[i] = even_jump_possible[idx];
        }

        if let Some((_, &idx)) = values_seen.range((Unbounded, Included(&arr[i]))).next_back() {
            even_jump_possible[i] = odd_jump_possible[idx];
        }

        values_seen.insert(arr[i], i);
    }

    odd_jump_possible.into_iter().filter(|&x| x).count() as i32
}
