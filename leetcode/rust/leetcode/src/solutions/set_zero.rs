use std::collections::HashSet;

pub struct Solution {}
impl Solution {
    /**
     * https://leetcode.cn/problems/set-matrix-zeroes/
     * 简单题
     */
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        if matrix.is_empty() {
            return;
        }
        let rows_len = matrix.len();
        let cols_len = matrix[0].len();
        let first_row_contains_zero = (matrix[0].iter()).any(|c| *c == 0);
        let first_cell_contains_zero = (0..rows_len).any(|r| matrix[r][0] == 0);
        for r in 1..rows_len {
            for c in 1..cols_len {
                if matrix[r][c] == 0 {
                    if matrix[r][0] != 0 {
                        for c_id in 0..c {
                            matrix[r][c_id] = 0;
                        }
                    }
                    if matrix[0][c] != 0 {
                        for r_id in 0..r {
                            matrix[r_id][c] = 0;
                        }
                    }
                } else if matrix[0][c] == 0 || matrix[r][0] == 0 {
                    matrix[r][c] = 0
                }
            }
        }
        if first_row_contains_zero {
            (0..cols_len).for_each(|c| matrix[0][c] = 0);
        }
        if first_cell_contains_zero {
            (0..rows_len).for_each(|r| matrix[r][0] = 0);
        }
    }
}
