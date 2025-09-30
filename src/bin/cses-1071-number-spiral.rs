// Created by Ayush Biswas at 2025/09/30 18:41
// https://cses.fi/problemset/task/1071
use cp_lib::*;

// @code begin
use cpio::*;
// const INF: u32 = 10u32.pow(9);
// const INF: usize = 4 * 10usize.pow(18);

sol_n! {
    fn solution(
        [x, y]: [usize; 2]
    ) -> usize {
        let corner = x.max(y);
        let c_value = (0..corner).map(|x| x*2).sum::<usize>() + 1;
        if x != corner {
            if corner % 2 == 1 {
                c_value + corner - x
            } else {
                c_value - corner + x
            }
        } else {
            if corner % 2 == 0 {
                c_value + corner - y
            } else {
                c_value - corner + y
            }
        }
    }
}

// @code end
