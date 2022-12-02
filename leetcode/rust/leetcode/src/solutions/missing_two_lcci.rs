pub struct Solution {}
impl Solution {
    /**
    https://leetcode.cn/problems/missing-two-lcci/submissions/
    整得有点粗暴，明天再想想优化方案
    */
    pub fn missing_two(mut nums: Vec<i32>) -> Vec<i32> {
        nums.extend([0, 0]);
        let mut id = 0;
        while id < nums.len() {
            let mut cur = nums[id] as usize;
            let mut expect_value = id + 1;
            while cur > 0 && cur != expect_value && cur <= nums.len() {
                nums[id] = nums[cur - 1];
                nums[cur - 1] = cur as i32;
                cur = nums[id] as usize;
                //println!("id:{},cur_value:{}",id,nums[id]);
            }
            id = id + 1;
        }
        let mut ans = vec![];
        id = 0;

        while id < nums.len() {
            let cur = (id + 1) as i32;
            if cur != nums[id] {
                ans.push(cur);
                if ans.len() >= 2 {
                    return ans;
                }
            }
            id = id + 1;
        }

        ans
    }
}
#[cfg(test)]
mod tests {
    // Import the necessary modules
    use super::Solution;

    // This test writes to a file
    #[test]
    fn test_missing_two() {
        let test_data = vec![(vec![2, 3], vec![1, 4])];
        for (mut nums, mut expect) in test_data {
            let got = Solution::missing_two(nums);
            assert_eq!(got, expect.to_vec());
        }
    }

    fn test_lalalalal() {
        let data: Vec<u8> = vec![
            116, 128, 0, 0, 0, 0, 0, 1, 171, 95, 114, 128, 0, 0, 13, 234, 3, 59, 57,
        ];
    }
}
