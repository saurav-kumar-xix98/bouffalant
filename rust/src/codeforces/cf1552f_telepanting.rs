#[cfg(test)]
mod test {

    #[test]
    fn testcase_1() {
        let src = vec![ 3, 6, 7, 8 ];
        let des = vec![ 2, 5, 4, 1 ];
        let state = vec![ false, true, false, true ];
        assert_eq!(23, telepanting(&src, &des, &state));
    }

    #[test]
    fn testcase_2() {
        let src = vec![ 454971987 ];
        let des = vec![ 406874902  ];
        let state = vec![ true  ];
        assert_eq!(503069073, telepanting(&src, &des, &state));
    }

    #[test]
    fn testcase_3() {
        let src = vec![ 243385510, 644426565, 708622105, 786625660, 899754846 ];
        let des = vec![ 42245605, 574769163, 208990040, 616437691, 382774619  ];
        let state = vec![ false, false, false, false, false ];
        assert_eq!(899754847, telepanting(&src, &des, &state));
    }

    #[test]
    fn testcase_4() {
        let src = vec![ 200000000, 600000000, 800000000, 900000000, 1000000000 ];
        let des = vec![ 100000000, 400000000, 300000000, 700000000, 500000000 ];
        let state = vec![ true, false, false, true, false ];
        assert_eq!(3511295, telepanting(&src, &des, &state));
    }

    pub fn telepanting(src: &[i32], des: &[i32], state: &[bool]) -> i32 {
        let divisor = 998244353;
        let n = src.len();
        let mut prefix_sum = vec![0i64; n + 1];
        let mut ans = (src[n - 1] as i64 + 1).rem_euclid(divisor);

        for i in 0..n {
            let index = src.partition_point(|&x| x < des[i]);

            let cost = (src[i] as i64 - des[i] as i64 + prefix_sum[i] - prefix_sum[index]).rem_euclid(divisor);
            prefix_sum[i + 1] = (prefix_sum[i] + cost).rem_euclid(divisor);

            if state[i] {
                ans = (ans + cost).rem_euclid(divisor);
            }
        }

        ans as i32
    }
}
