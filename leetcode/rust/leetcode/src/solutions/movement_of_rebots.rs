pub struct Solution {}
impl Solution {
    /**
     * https://leetcode.cn/problems/movement-of-robots/?envType=daily-question&envId=2023-10-10
     * math,O(N)
     * 2 <= nums.length <= 105
     * -2 * 1e9 <= nums[i] <= 2 * 1e9
     * 0 <= d <= 1e9
     * nums.length == s.length
     */
    pub fn sum_distance(nums: Vec<i32>, s: String, d: i32) -> i32 {
        let mut nums_final = s
            .as_bytes()
            .iter()
            .enumerate()
            .map(|(id, b)| {
                if *b == b'L' {
                    /*Pay attention to the precision, nums[i]+/-d(1) 2*1e9+1e9 > i32::MAX */
                    nums[id] as i64 - d as i64
                } else {
                    nums[id] as i64 + d as i64
                }
            })
            .collect::<Vec<i64>>();
        nums_final.sort();

        let total = nums_final.len();
        let modd = 1000000007;
        let mut id = total / 2;
        let mut ans = if total % 2 == 0 {
            let cur_cnt = ((total - id) * id) as i64 % modd;
            let dis1 = (nums_final[id] - nums_final[id - 1]) % modd;
            id = id - 1;
            cur_cnt * dis1
        } else {
            0
        };
        while id > 0 {
            let cur = (((total - id) * id) as i64) % modd;
            let dis1 = (nums_final[id] - nums_final[id - 1]) % modd;
            // println!("id {},dis1:{},cur{}",id,dis1,cur);
            ans = ans % modd + (cur * dis1) % modd;

            let dis2 = (nums_final[total - id] - nums_final[total - id - 1]) % modd;
            ans = ans % modd + (cur * dis2) % modd;
            //println!("total-id {},dis1:{},cur{}",total-id,dis2,cur);
            id = id - 1;
        }
        return (ans % modd) as i32;
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    #[test]
    fn test_sum_distance() {
        let test_cases = vec![
            (vec![-2, 0, 2], "RLL", 3, 8),
            (vec![1, 0], "RL", 2, 5),
            (vec![-10, -13, 10, 14, 11], "LRLLR", 2, 146),
            (vec![-2000000000, 2000000000], "LR", 1000000000, 999999965),
        ];
        for (nums, s, d, expect) in test_cases {
            let got = Solution::sum_distance(nums, s.to_string(), d);
            assert_eq!(got, expect);
        }
    }
}
