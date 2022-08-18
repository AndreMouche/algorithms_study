pub struct Solution {}
impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let bts = s.as_bytes();
        let mut longest_len = 0;
        let mut longest_left = 0;
        let mut mid = 0;
        while mid < bts.len() {
            let mut left = mid as i32;
            let mut right = mid;
            while right + 1 < bts.len() && bts[right] == bts[right + 1] {
                right = right + 1;
            }
            mid = right + 1;
            while left >= 0 && right < bts.len() && bts[left as usize] == bts[right] {
                left = left - 1;
                right = right + 1;
            }
            let curlen = right as i32 - left - 1;
            if longest_len < curlen {
                longest_left = left + 1;
                longest_len = curlen;
            }
        }
        let right = longest_len + longest_left;
        return s
            .get(longest_left as usize..right as usize)
            .unwrap()
            .to_string();
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    /**
     * 最长回文子串
      https://leetcode.cn/problems/longest-palindromic-substring/submissions/
    */
    #[test]
    fn test_longest_palindrome() {
        let test_case = vec![("cbbd", "bb"), ("babad", "bab")];
        for (s, expect) in test_case {
            let got = Solution::longest_palindrome(s.to_string());
            assert_eq!(got, expect.to_string());
        }
    }
}
