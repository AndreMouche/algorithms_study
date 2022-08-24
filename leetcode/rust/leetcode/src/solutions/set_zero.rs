use std::collections::HashSet;

pub struct Solution {}
impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        if matrix.is_empty() {
            return;
        }
        let mut rows = vec![];
        let mut left_rows = vec![];
        let mut cols = HashSet::new();
        let rows_len = matrix.len();
        let cols_len = matrix[0].len();
        for r in 0..rows_len {
            let mut zero_r = false;
            for c in 0..cols_len {
                if matrix[r][c] == 0 {
                    zero_r = true;
                    cols.insert(c);
                }
            }
            if !zero_r {
                left_rows.push(r);
            } else {
                rows.push(r);
            }
        }
        if rows.is_empty() {
            return;
        }
        // set rows
        rows.iter().for_each(|r| {
            for c in 0..cols_len {
                matrix[*r][c] = 0;
            }
        });
        if left_rows.is_empty() {
            return;
        }
        cols.iter().for_each(|c| {
            left_rows.iter().for_each(|r| {
                matrix[*r][*c] = 0;
            });
        });
    }
}
