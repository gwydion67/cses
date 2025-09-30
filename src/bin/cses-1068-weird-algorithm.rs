// Created by Ayush Biswas at 2025/09/30 16:26
// https://cses.fi/problemset/task/1068
use cp_lib::*;

// @code begin
use cpio::*;
use itertools::Itertools;
// const INF: u32 = 10u32.pow(9);
// const INF: usize = 4 * 10usize.pow(18);

sol! {
    fn solution(
        n: usize,
    ) -> Words<usize> {
        (1..).scan(n, |state, _| {
            let v = *state;
            if v == 0{
                None
            } else if v == 1 {
                *state = 0;
                Some(v)
            } else if v%2 == 0 {
                *state = v/2;
                Some(v)
            } else {
                *state = 3*v+1;
                Some(v)
            }
        }).collect_vec().into()
    }
}

// @code end
