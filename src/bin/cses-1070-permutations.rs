// Created by Ayush Biswas at 2025/09/30 18:32
// https://cses.fi/problemset/task/1070
use cp_lib::*;

// @code begin
use cpio::*;
use itertools::Itertools;
// const INF: u32 = 10u32.pow(9);
// const INF: usize = 4 * 10usize.pow(18);

sol! {
    fn solution(
        n: usize,
    ) -> CPResult<Words<usize>, String> {
        if n == 3 || n == 2 {
            return Failure("NO SOLUTION".into())
        }

        let (even, odd): (Vec<_>, Vec<_>) = (1..=n)
            .partition(|n| n % 2 == 0);

        Success(
            odd.into_iter().rev().chain(
                even.into_iter().rev()
            ).collect_vec().into()
        )
    }
}

// @code end
