use std::collections::HashSet;
pub struct Solution {}
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut set = HashSet::new();
        for num in nums {
            if set.contains(&num) {
                return true;
            }
            set.insert(num);
        }
        return false;
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn test_contains_duplicate() {
        let test_data = vec![
            (vec![1, 2, 3, 1], true),
            (vec![1, 2, 3, 4], false),
            (vec![1, 1, 1, 3, 3, 4, 3, 2, 4, 2], true),
        ];
        for (nums, expect) in test_data {
            let got = Solution::contains_duplicate(nums);
            assert_eq!(got, expect);
        }
    }
}
