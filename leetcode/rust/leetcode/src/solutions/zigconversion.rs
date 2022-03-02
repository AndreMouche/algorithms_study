pub struct Solution {}
impl Solution {
    /*
    ref https://leetcode.com/problems/zigzag-conversion/
    0 2numRows-2-row*2   +2*row
    */
    pub fn convert(s: String, num_rows: i32) -> String {
        if s.len() <= 1 || num_rows == 1 {
            return s;
        }
        let mut ans: Vec<u8> = vec![];
        let su = s.as_bytes();
        let cur_dis = 2 * num_rows as usize - 2;
        //0 2numRows-2-row*2   +2*row
        for id in 0..num_rows {
            let mut cur = id as usize;
            let mid_dis = cur_dis - 2 * (id as usize);

            while cur < s.len() {
                ans.push(su[cur as usize]);
                let mid = cur + mid_dis;
                cur = cur + cur_dis;
                if mid >= s.len() {
                    break;
                }
                if mid_dis == cur_dis {
                    continue;
                }
                if mid_dis == 0 {
                    continue;
                }
                ans.push(su[mid]);
            }
        }
        String::from_utf8(ans).unwrap()
    }
}

/*
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"


Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/
#[cfg(test)]
mod tests {
    // Import the necessary modules
    use super::Solution;

    // This test writes to a file
    #[test]
    fn test_convert() {
        let test_data = vec![
            ("PAYPALISHIRING", 4, "PINALSIGYAHRPI"),
            ("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"),
            ("A", 1, "A"),
        ];
        for (s, num_rows, expect) in test_data.iter() {
            let got = Solution::convert(s.to_string(), *num_rows);
            assert_eq!(got, expect.to_string());
        }
    }
}
