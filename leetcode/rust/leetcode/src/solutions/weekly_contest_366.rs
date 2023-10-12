pub struct Solution {}
impl Solution {
    /**
     * https://leetcode.cn/contest/weekly-contest-366/problems/divisible-and-non-divisible-sums-difference/
     */
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let mut ans = 0;
        for i in 1..n + 1 {
            if i % m == 0 {
                ans = ans - i;
            } else {
                ans = ans + i;
            }
        }
        ans
    }
    /**
     * https://leetcode.cn/contest/weekly-contest-366/problems/minimum-processing-time/
     */
    pub fn min_processing_time(mut processor_time: Vec<i32>, mut tasks: Vec<i32>) -> i32 {
        tasks.sort();
        processor_time.sort();
        let mut ans = processor_time[0] + tasks[tasks.len() - 1];
        for i in 1..processor_time.len() {
            if tasks.len() < i * 4 + 1 {
                return std::cmp::max(ans, processor_time[processor_time.len() - 1]);
            }
            ans = std::cmp::max(ans, tasks[tasks.len() - i * 4 - 1] + processor_time[i]);
        }
        ans
    }

    /*
    https://leetcode.cn/problems/apply-operations-to-make-two-strings-equal/description/
    DP O(N^3):
    dp[i][j] represents the cost required to make s1[i][j] and s2[i][j] identical.
    dp[i][j] = min(dp[i][k-1]+dp[k][j-1]+x) (i+1<k<j)  reverse k with j with cost x.
    meanwhile consider reverse j-1,j together with cost 1*(diff_offset[j]-diff_offset[j-1])
    complex: O(N^3). 1 <= n, x <= 500
     */
    pub fn min_operations2(s1: String, s2: String, x: i32) -> i32 {
        let mut diff_offset = vec![];
        for i in 0..s1.len() {
            if s1.as_bytes()[i] != s2.as_bytes()[i] {
                diff_offset.push(i as i32);
            }
        }
        if diff_offset.len() % 2 != 0 {
            return -1;
        }
        if diff_offset.is_empty() {
            return 0;
        }
        if x <= 1 {
            return (diff_offset.len() / 2) as i32 * x;
        }

        let mut dp = vec![];
        for i in 0..diff_offset.len() - 1 {
            //println!("offset[{}]={}",i,diff_offset[i]);
            dp.push(vec![0; diff_offset.len()]);
            dp[i][i + 1] = std::cmp::min(diff_offset[i + 1] - diff_offset[i], x);
        }

        for step in 1..diff_offset.len() / 2 {
            for i in 0..diff_offset.len() - 1 {
                let right = i + 2 * step + 1;
                if right >= diff_offset.len() {
                    break;
                }
                dp[i][right] = std::cmp::min(
                    dp[i][right - 2] + dp[right - 1][right],
                    dp[i + 1][right - 1] + x,
                );
                let mut left = i + 2;
                // Reverse an element（left） selected from front to back with the last one(right) at a cost of X.
                while left < right - 1 {
                    dp[i][right] =
                        std::cmp::min(dp[i][left - 1] + dp[left + 1][right - 1] + x, dp[i][right]);
                    left = left + 2;
                }
            }
        }
        return dp[0][diff_offset.len() - 1];
    }

    /*
    https://leetcode.cn/problems/apply-operations-to-make-two-strings-equal/description/
    DP O(N^2):
    dp[i][j] represents the cost required to make s1[i][j] and s2[i][j] identical.
    dp[i][j] = min{
        dp[i+1][j-1]+x   // offset[i] and offset[j] cost x
        dp[i][i+1]+dp[i+2][j], // consider:previous together.
        dp[i][j-2]+dp[j-1][j], // consider: last to together.
    }
    example:
    {0 1 2 3 4 5}
    dp[0][5] = min{dp[1][4]+x,
        dp[2][5]+dp[0][1], // possibble case: 2 and 5 are togher with x
        dp[0][3]+dp[4,5]  // possible case: 0 and 3 are togher with x
    }
    complex: O(N^2). 1 <= n, x <= 500
     */
    pub fn min_operations(s1: String, s2: String, x: i32) -> i32 {
        let mut diff_offset = vec![];
        for i in 0..s1.len() {
            if s1.as_bytes()[i] != s2.as_bytes()[i] {
                diff_offset.push(i as i32);
            }
        }
        if diff_offset.len() % 2 != 0 {
            return -1;
        }
        if diff_offset.is_empty() {
            return 0;
        }
        if x <= 1 {
            return (diff_offset.len() / 2) as i32 * x;
        }

        let mut dp = vec![];
        for i in 0..diff_offset.len() - 1 {
            //println!("offset[{}]={}",i,diff_offset[i]);
            dp.push(vec![0; diff_offset.len()]);
            dp[i][i + 1] = std::cmp::min(diff_offset[i + 1] - diff_offset[i], x);
        }

        for step in 1..diff_offset.len() / 2 {
            for i in 0..diff_offset.len() - 1 {
                let right = i + 2 * step + 1;
                if right >= diff_offset.len() {
                    break;
                }
                dp[i][right] = std::cmp::min(
                    dp[i][right - 2] + dp[right - 1][right],
                    dp[i + 1][right - 1] + x,
                );
                dp[i][right] = std::cmp::min(dp[i][right], dp[i][i + 1] + dp[i + 2][right]);
            }
        }
        return dp[0][diff_offset.len() - 1];
    }

    /**
     * https://leetcode.cn/problems/apply-operations-on-array-to-maximize-sum-of-squares/description/
     * (nums[i],num[j]) turns to (nums[i]|nums[j],nums[i]&nums[j])
     * => the total numbers of 1 in each binary keeps the same.
     * Count the number of 1s in the binary representation, and redistribute them in descending order.
     *  1 <= k <= nums.length <= 1e5
     * 1 <= nums[i] <= 1e9
     */
    pub fn max_sum(nums: Vec<i32>, mut k: i32) -> i32 {
        let mut ans = 0;
        let mut bit = vec![0; 32];
        let mut max_length = 0;
        for mut num in nums {
            let mut idx = 0;
            while num > 0 {
                bit[idx] = bit[idx] + (num & 1);
                num = num >> 1;
                idx = idx + 1;
            }
            max_length = std::cmp::max(idx, max_length);
        }
        let modd = 1000000007;
        while k > 0 {
            k = k - 1;
            let mut cur: i64 = 0;
            for id in 0..max_length {
                //println!("i {} {}",id,bit[id]);
                if bit[id] > 0 {
                    bit[id] = bit[id] - 1;
                    cur = cur + (1 << id);
                }
            }
            //println!("cur {},{},{}",cur,cur*cur,modd);
            cur = cur % modd;
            ans = (ans + (cur * cur) % modd) % modd
        }

        return ans as i32;
    }

    /**
     * https://leetcode.cn/problems/find-the-array-concatenation-value/
     */
    pub fn find_the_array_conc_val(nums: Vec<i32>) -> i64 {
        let mut ans = 0;
        for id in 0..nums.len() / 2 {
            let mut right = nums[nums.len() - id - 1];
            ans = ans + right as i64;
            let mut left = nums[id];
            while right > 0 {
                right = right / 10;
                left = left * 10;
            }
            ans = ans + left as i64;
        }
        if nums.len() % 2 != 0 {
            ans = ans + nums[nums.len() / 2] as i64;
        }
        return ans;
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    #[test]
    fn test_min_operations() {
        let test_case = vec![(
        "100010010100111100001110101111100001001101011010100111101011100100011111110001011001001",
        "000001100010010011111101100101111011101110010001001010100101011100011110000111010011010",
        6,
        38,
        )
       ];
        for (s1, s2, x, n) in test_case {
            let got = Solution::min_operations(s1.into(), s2.into(), x);
            assert_eq!(got, n);
        }
    }

    #[test]
    fn test_max_sum() {
        let test_cases = vec![
            (vec![2, 6, 5, 8], 2, 261),
            (vec![4, 5, 4, 7], 3, 90),
            (vec![1000000000, 1000000000, 1000000000], 3, 147),
        ];
        for (nums, k, expect) in test_cases {
            let got = Solution::max_sum(nums, k);
            assert_eq!(got, expect);
        }
    }
}
