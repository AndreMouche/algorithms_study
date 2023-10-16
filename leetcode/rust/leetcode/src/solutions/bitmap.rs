struct Solution {}
impl Solution {
    /**
     * https://leetcode.cn/problems/single-number-iii/description/
     * 1. 所有数字异或，得到的结果是两个只出现一次的数字的异或结果
     * 2. 找到这个结果中第一个为 1 的位，这个位说明两个数字在这个位上不同
     * 3. 根据这个位，将所有数字分成两组，这两个数字分别在不同的组中
     * 4. 对每组进行异或，得到的结果就是这两个数字
     */
    fn single_number(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![0; 2];
        let mut xor = 0;
        //The result of XORing all the numbers is the XOR result of the two numbers that only appear once.
        for num in nums.iter() {
            xor = xor ^ num;
        }

        //Find the first bit in this result that is 1, which indicates that the two numbers are different at this bit.
        let mut mask = 1;
        while xor & mask == 0 {
            mask = mask << 1;
        }

        //Divide all the numbers into two groups based on this bit, with each number in a different group.
        for num in nums {
            //XOR each group separately to obtain the results of the two numbers.
            if num & mask == 0 {
                ans[0] = ans[0] ^ num;
            } else {
                ans[1] = ans[1] ^ num;
            }
        }
        return ans;
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    #[test]
    fn test_single_number() {
        let test_cases = vec![
            (vec![1, 2, 1, 3, 2, 5], vec![3, 5]),
            (vec![-1, 0], vec![-1, 0]),
            (vec![0, 1], vec![0, 1]),
        ];
        for (nums, expect) in test_cases {
            let mut got = Solution::single_number(nums);
            got.sort();
            assert_eq!(got, expect);
        }
    }
}
