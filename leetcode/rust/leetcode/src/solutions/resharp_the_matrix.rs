pub struct Solution {}
impl Solution {
    /*https://leetcode.cn/problems/reshape-the-matrix/ 简单题*/
    pub fn matrix_reshape(mat: Vec<Vec<i32>>, r: i32, c: i32) -> Vec<Vec<i32>> {
        let mut rows = mat.len();
        if mat.is_empty() {
            return mat.clone();
        }
        let mut cols = mat[0].len();
        if (rows * cols) as i32 != r * c || rows == r as usize {
            return mat.clone();
        }
        rows = r as usize;
        cols = c as usize;
        let mut ans = Vec::with_capacity(r as usize);
        ans.push(Vec::with_capacity(c as usize));
        let mut cur_row = 0;
        for rows in mat {
            for col in rows {
                if ans[cur_row].len() >= cols {
                    ans.push(Vec::with_capacity(cols));
                    cur_row = cur_row + 1;
                }
                ans[cur_row].push(col);
            }
        }
        ans
    }
}
