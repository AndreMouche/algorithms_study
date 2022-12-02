/**
 * ref https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
 * You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.



Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]


Constraints:

n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'.
 */
struct Solution {}
impl Solution {
    /**
     * O(N)
     */
    pub fn min_operations(boxes: String) -> Vec<i32> {
        let mut ans = vec![0; boxes.len()];
        let mut left_count = 0;
        let mut left_total = 0;
        let mut right_count = 0;
        let mut right_total = 0;
        for (idx, b) in boxes.as_bytes().iter().enumerate() {
            if *b == b'1' {
                right_total = right_total + idx as i32;
                right_count = right_count + 1;
            }
        }
        for (idx, b) in boxes.as_bytes().iter().enumerate() {
            if idx > 0 {
                left_total = (left_total + left_count);
                right_total = (right_total - right_count);
            }
            ans[idx] = left_total + right_total;

            if *b == b'1' {
                left_count = left_count + 1;
                right_count = right_count - 1;
            }
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    #[test]
    fn test_minum_number_of_operationsxxx() {
        let test_data = vec![("001011", vec![11, 8, 5, 4, 3, 4]), ("110", vec![1, 1, 3])];
        for (boxes, expect) in test_data {
            let got = Solution::min_operations(boxes.to_string());
            assert_eq!(got, expect);
        }
    }
}
