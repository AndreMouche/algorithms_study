struct Solution {}
/**
 * https://leetcode.cn/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/description/
 */
impl Solution {
    pub fn nearest_valid_point(x: i32, y: i32, points: Vec<Vec<i32>>) -> i32 {
        let mut offset: i32 = -1;
        let mut min_dis = 0;
        for (id, point) in points.iter().enumerate() {
            if point[0] != x && point[1] != y {
                continue;
            }
            let distance = (point[0] - x).abs() + (point[1] - y).abs();
            if offset == -1 || distance < min_dis {
                offset = id as i32;
                min_dis = distance;
            }
        }
        offset
    }
}
#[cfg(test)]

mod tests {
    use super::Solution;
    #[test]
    fn test_nearest_valid_point() {
        let test_data = vec![
            (
                (3, 4),
                vec![vec![1, 2], vec![3, 1], vec![2, 4], vec![2, 3], vec![4, 4]],
                2,
            ),
            ((3, 4), vec![vec![3, 4]], 0),
            ((3, 4), vec![vec![2, 3]], -1),
        ];
        for ((x, y), points, expect) in test_data {
            let got = Solution::nearest_valid_point(x, y, points);
            assert_eq!(got, expect);
        }
    }
}
