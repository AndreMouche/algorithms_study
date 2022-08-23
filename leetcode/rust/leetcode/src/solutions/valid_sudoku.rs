pub struct Solution {}
use std::collections::HashSet;
impl Solution {
    /**
     * https://leetcode.cn/problems/valid-sudoku/
     * 简单题
     */
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        if board.len() != 9 {
            return false;
        }
        if board.iter().any(|row| row.len() != 9) {
            return false;
        }
        let mut rows = vec![HashSet::new(); 9];
        let mut cols = vec![HashSet::new(); 9];
        let mut sub = vec![HashSet::new(); 9];
        // check rows
        for rid in 0..9 {
            for cid in 0..9 {
                let cur = board[rid][cid];
                if cur == '.' {
                    continue;
                }
                // insert into rows
                if Solution::check_and_insert(&mut rows[rid], cur) {
                    return false;
                }
                if Solution::check_and_insert(&mut cols[cid], cur) {
                    return false;
                }
                let sub_id = (rid / 3) * 3 + cid / 3;
                if Solution::check_and_insert(&mut sub[sub_id], cur) {
                    return false;
                }
            }
        }
        true
    }

    fn check_and_insert(data: &mut HashSet<char>, v: char) -> bool {
        if data.contains(&v) {
            return true;
        }
        data.insert(v);
        return false;
    }
}
