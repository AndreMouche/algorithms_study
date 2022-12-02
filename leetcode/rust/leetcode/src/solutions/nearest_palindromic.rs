#[cfg(test)]
mod tests {
    // Import the necessary modules
    use super::Solution;

    // This test writes to a file
    #[test]
    fn test_missing_two() {
        let test_data = vec![
            (vec![2,3],vec![1,4]),
            
        ];
        for (nums,expect) in test_data.iter() {
            let got = Solution::missing_two(nums);
            assert_eq!(got, expect);
        }
    }
}
