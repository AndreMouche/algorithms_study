pub struct Solution {}
impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        }
        let mut max_pre_sum = nums[0];
        let mut max_sum = max_pre_sum;
        nums.iter().skip(1).for_each(|x| {
            if max_pre_sum < 0 {
                max_pre_sum = 0;
            }
            max_pre_sum = max_pre_sum + x;
            if max_pre_sum > max_sum {
                max_sum = max_pre_sum;
            }
        });
        return max_sum;
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    /**
     * https://leetcode.cn/problems/maximum-subarray/
     * 简单题，不多说。
     */
    #[test]
    fn test_max_sub_array() {
        let test_data = vec![
            (vec![-2, 1, -3, 4, -1, 2, 1, -5, 4], 6),
            (vec![5, 4, -1, 7, 8], 23),
            (vec![1], 1),
            (vec![-1], -1),
        ];
        for (vals, expect) in test_data {
            let got = Solution::max_sub_array(vals);
            assert_eq!(expect, got);
        }
    }
}
