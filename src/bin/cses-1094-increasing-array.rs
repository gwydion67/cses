// Created by Ayush Biswas at 2025/09/30 17:12
// https://cses.fi/problemset/task/1094
use cp_lib::*;

// @code begin
use cpio::*;
// const INF: u32 = 10u32.pow(9);
// const INF: usize = 4 * 10usize.pow(18);

sol! {
    fn solution(
        n: usize,
        a: [usize]
    ) -> usize {
        a.into_iter()
            .scan(0, |state, ai| {
                let v = *state;
                if v > ai {
                    Some(v - ai)
                } else {
                    *state = ai;
                    Some(0)
                }
            })
            .sum()

    }
}

// @code end
