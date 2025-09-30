// Created by Ayush Biswas at 2025/09/30 16:51
// https://cses.fi/problemset/task/1083
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
        (1..=n).reduce(|a, b| a ^ b).unwrap() ^
        a.into_iter().reduce(|a, b| a ^ b).unwrap()
    }
}

// @code end
