pub struct Solution {}
impl Solution {
    /**
     * 主要考字符串的操作，简单题。
     * https://leetcode.cn/problems/generate-a-string-with-characters-that-have-odd-counts/
     */
    pub fn generate_the_string(n: i32) -> String {
        if n == 0 {
            return String::new();
        }
        if n % 2 == 0 {
            let mut s = "a".repeat((n - 1) as usize);
            s.push('b');
            return s;
        } else {
            return "a".repeat(n as usize);
        }
    }
}
