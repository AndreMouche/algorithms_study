pub struct Solution {}
impl Solution {
    /**
     *  https://leetcode.cn/problems/asteroid-collision/submissions/
     * 题解：模拟题，直接用栈 模拟即可，注意事项：
     * 同一方向不会碰撞
     * 相反方向不会碰撞
     * 相对方向会碰撞
     */
    pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![];
        for cur in asteroids {
            loop {
                let prev = if let Some(prev_node) = ans.last() {
                    *prev_node
                } else {
                    ans.push(cur);
                    break;
                };
                // 相同方向或者相反方向，不会碰撞
                if prev * cur > 0 || prev < 0 {
                    ans.push(cur);
                    break;
                }
                // 体重一样，碰没了
                if prev + cur == 0 {
                    ans.pop();
                    break;
                }
                // 当前想要向左走，碰上前一个想要往右边走
                // 当前的质量更重，前一个被干掉，继续往左碰撞。
                if prev + cur < 0 {
                    // prev will be broke by current value.
                    ans.pop();
                    continue;
                }
                // 当前的质量更小，当前的被干掉。
                break;
            }
        }
        return ans;
    }
}

#[cfg(test)]
mod tests {
    // Import the necessary modules
    use super::Solution;

    /**
         * 示例 1：

    输入：asteroids = [5,10,-5]
    输出：[5,10]
    解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。
    示例 2：

    输入：asteroids = [8,-8]
    输出：[]
    解释：8 和 -8 碰撞后，两者都发生爆炸。
    示例 3：

    输入：asteroids = [10,2,-5]
    输出：[10]
    解释：2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/asteroid-collision
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
         */
    #[test]
    fn test_asteroid_collision() {
        let test_data = vec![
            // asteroids = [5,10,-5]
            (vec![5, 10, -5], vec![5, 10]),
            // asteroids = [8,-8]
            (vec![8, -8], vec![]),
            // asteroids = [10,2,-5]
            (vec![10, 2, -5], vec![10]),
            // [-2,-1,1,2],
            (vec![-2, -1, 1, 2], vec![-2, -1, 1, 2]),
            (vec![1, -2, -2, -2], vec![-2, -2, -2]),
        ];
        for (asteroids, expect) in test_data {
            let got = Solution::asteroid_collision(asteroids);
            assert_eq!(got, expect);
        }
    }
}
