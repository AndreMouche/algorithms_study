pub struct Solution {}
impl Solution {
    //https://leetcode.cn/contest/weekly-contest-365/problems/maximum-value-of-an-ordered-triplet-i/
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let mut ans: i64 = 0;
        for i in 0..nums.len() {
            for j in i + 1..nums.len() {
                let sub = (nums[i] - nums[j]) as i64;
                if sub == 0 {
                    continue;
                }
                for k in j + 1..nums.len() {
                    if (sub < 0 && nums[k] >= 0) || (sub > 0 && nums[k] <= 0) {
                        continue;
                    }
                    let cur = sub * (nums[k] as i64);
                    ans = std::cmp::max(cur, ans);
                }
            }
        }
        return ans;
    }
    /*
    https://leetcode.cn/contest/weekly-contest-365/problems/maximum-value-of-an-ordered-triplet-ii/
    3 <= nums.length <= 10^5
    1 <= nums[i] <= 10^6
    reduce Complexity to O(N)
    */
    pub fn maximum_triplet_value2(nums: Vec<i32>) -> i64 {
        let mut skip_zero = vec![];
        for v in 0..nums.len() {
            if nums[v] != 0 {
                skip_zero.push(nums[v]);
            }
        }
        let mut ans = 0;
        let mut min = vec![0; skip_zero.len()];
        let mut max = vec![0; skip_zero.len()];
        let mut id = skip_zero.len() - 1;
        min[id] = skip_zero[id];
        max[id] = skip_zero[id];
        while id > 0 {
            id = id - 1;
            min[id] = std::cmp::min(min[id + 1], skip_zero[id]);
            max[id] = std::cmp::max(max[id + 1], skip_zero[id]);
        }

        let mut seq_min = vec![0; skip_zero.len()];
        let mut seq_max = vec![0; skip_zero.len()];
        id = 0;
        seq_max[id] = skip_zero[0];
        seq_min[id] = skip_zero[0];
        while id < skip_zero.len() - 1 {
            id = id + 1;
            seq_min[id] = std::cmp::min(seq_min[id - 1], skip_zero[id]);
            seq_max[id] = std::cmp::max(seq_max[id - 1], skip_zero[id]);
        }

        for j in 1..skip_zero.len() - 1 {
            println!("[{}]value:{}", j, skip_zero[j]);
            println!("seq:{},{}", seq_min[j - 1], seq_max[j - 1]);

            let sub1 = (seq_min[j - 1] - skip_zero[j]) as i64;
            let sub2 = (seq_max[j - 1] - skip_zero[j]) as i64;
            ans = std::cmp::max(sub1 * (min[j + 1]) as i64, ans);
            ans = std::cmp::max(sub1 * (max[j + 1]) as i64, ans);
            ans = std::cmp::max(sub2 * (min[j + 1]) as i64, ans);
            ans = std::cmp::max(sub2 * (max[j + 1]) as i64, ans);
        }
        ans
    }
}
#[cfg(test)]
mod tests {
    use super::Solution;
    #[test]
    fn test_maximum_triplet_value2() {
        let test_case = vec![
            (vec![1000000, 1, 1000000], 999999000000),
            (vec![12, 6, 1, 2, 7], 77),
            (vec![1, 10, 3, 4, 19], 133),
            (vec![1, 2, 3], 0),
        ];
        for (nums, expect) in test_case {
            let got = Solution::maximum_triplet_value2(nums);
            assert_eq!(got, expect);
        }
    }
}
