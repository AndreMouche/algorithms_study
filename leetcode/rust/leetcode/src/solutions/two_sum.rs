use std::collections::HashMap;
pub struct Solution {}
impl Solution {
    /**
     * https://leetcode.cn/problems/two-sum/
     * 简单题。
     */
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut data = HashMap::new();
        for (idx, num) in nums.iter().enumerate() {
            let expect = target - num;
            if let Some(v) = data.get(&expect) {
                return vec![*v, idx as i32];
            }
            data.insert(num, idx as i32);
        }
        return vec![];
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    /**
     * cargo test test_two_sum
     */
    #[test]
    fn test_two_sum() {
        let test_data = vec![
            (vec![2, 7, 11, 15], 9, vec![0, 1]),
            (vec![3, 2, 4], 6, vec![1, 2]),
            (vec![3, 3], 6, vec![0, 1]),
        ];
        for (nums, target, expect) in test_data {
            let got = Solution::two_sum(nums, target);
            assert_eq!(got, expect);
        }
    }
}
