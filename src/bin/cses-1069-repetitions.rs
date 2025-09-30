// Created by Ayush Biswas at 2025/09/30 17:06
// https://cses.fi/problemset/task/1069
use cp_lib::*;

// @code begin
use cpio::*;
use itertools::Itertools;
// const INF: u32 = 10u32.pow(9);
// const INF: usize = 4 * 10usize.pow(18);

sol! {
    fn solution(
        s: [char]
    ) -> usize {
        s
            .into_iter()
            .group_by(|&c| c)
            .map(|g| g.len())
            .max()
            .unwrap()
    }
}

// @code end
