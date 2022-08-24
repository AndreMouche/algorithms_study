pub struct Solution {}
impl Solution {
    /**
    https://leetcode.cn/problems/first-unique-character-in-a-string/
    简单题
    */
    pub fn first_uniq_char(s: String) -> i32 {
        let mut mark: Vec<i16> = vec![-1; 26];
        for (idx, v) in s.as_bytes().iter().enumerate() {
            let cur = (v - b'a') as usize;
            if mark[cur] == -1 {
                mark[cur] = idx as i16;
            } else {
                mark[cur] = -2;
            }
        }

        let mut ans = s.len() as i16;
        for idx in mark {
            if idx < 0 {
                continue;
            }
            if ans > idx {
                ans = idx;
            }
        }
        if ans == s.len() as i16 {
            return -1;
        }
        return ans as i32;
    }
}
