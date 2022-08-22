pub struct Solution {}

impl Solution {
    /**
     * https://leetcode.cn/problems/pascals-triangle/
     * 简单题，懒得弄，简单写个递归吧
     */
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        if num_rows <= 0 {
            return vec![];
        }
        if num_rows == 1 {
            return vec![vec![1]];
        }
        let mut ans = Solution::generate(num_rows - 1);
        let mut cur = vec![1];
        let mut iter = ans[ans.len() - 1].iter().skip(1);
        let mut prev = 1;
        while let Some(v) = iter.next() {
            cur.push(*v + prev);
            prev = *v;
        }
        cur.push(1);
        ans.push(cur);
        ans
    }
}
