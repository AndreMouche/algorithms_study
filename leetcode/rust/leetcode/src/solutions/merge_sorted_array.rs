pub struct Solution {}
impl Solution {
    /*
    https://leetcode.cn/problems/merge-sorted-array/
    merge sort 简单题
    */
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let len = (m + n) as usize;
        nums1.resize(len as usize, 0);
        let mut id1 = m as usize;
        let mut id2 = n as usize;
        let mut id = len as usize;
        while id1 > 0 && id2 > 0 {
            id = id - 1;
            if nums1[id1 - 1] < nums2[id2 - 1] {
                id2 = id2 - 1;
                nums1[id] = nums2[id2];
                continue;
            }
            id1 = id1 - 1;
            nums1[id] = nums1[id1];
        }

        while id2 > 0 {
            id2 = id2 - 1;
            nums1[id2] = nums2[id2];
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn test_merge() {
        let test_data = vec![
            (
                vec![1, 2, 3, 0, 0, 0],
                3,
                vec![2, 5, 6],
                3,
                vec![1, 2, 2, 3, 5, 6],
            ),
            (vec![1], 1, vec![], 0, vec![1]),
            (vec![0], 0, vec![1], 1, vec![1]),
            (
                vec![4, 5, 6, 0, 0, 0],
                3,
                vec![1, 2, 3],
                3,
                vec![1, 2, 3, 4, 5, 6],
            ),
        ];
        for (mut nums1, m, mut nums2, n, expect) in test_data {
            Solution::merge(&mut nums1, m, &mut nums2, n);
            assert_eq!(nums1, expect);
        }
    }
}
