use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }

    pub fn visit(&self, cur_level: usize, mut sum: Vec<i32>) -> Vec<i32> {
        if let Some(v) = sum.get_mut(cur_level) {
            *v = *v + self.val;
        } else {
            sum.push(self.val);
        }
        if let Some(left) = self.left.as_ref() {
            sum = left.as_ref().borrow().visit(cur_level + 1, sum);
        }
        if let Some(right) = &self.right {
            sum = right.as_ref().borrow().visit(cur_level + 1, sum);
        }
        return sum;
    }
    pub fn build(vals: Vec<Option<i32>>) -> Option<Rc<RefCell<TreeNode>>> {
        if vals.is_empty() {
            return None;
        }
        let mut stack = VecDeque::new();
        let root = Rc::new(RefCell::new(TreeNode::new(vals[0].unwrap())));
        stack.push_back(root.clone());
        let mut cur_index = 1;
        while let Some(cur_node) = stack.pop_front() {
            if cur_index >= vals.len() {
                break;
            }
            println!("cur {}", cur_node.as_ref().borrow().val);
            if let Some(v) = vals[cur_index] {
                println!("left {}", v);
                let left = Rc::new(RefCell::new(TreeNode::new(v)));
                cur_node.borrow_mut().left = Some(left.clone());
                stack.push_back(left);
            } else {
                println!("empty left");
            }
            cur_index = cur_index + 1;
            if cur_index >= vals.len() {
                break;
            }
            if let Some(v) = vals[cur_index] {
                println!("right {}", v);
                let right = Rc::new(RefCell::new(TreeNode::new(v)));
                cur_node.borrow_mut().right = Some(right.clone());
                stack.push_back(right);
            } else {
                println!("empty right");
            }
            cur_index = cur_index + 1;
        }
        return Some(root);
    }
}

pub struct Solution {}
use std::borrow::Borrow;
impl Solution {
    /**
     * https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/
     * 数据结构，树
     * 没啥可说的，直接模拟就可以了。
     */
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut sums = vec![];
        if let Some(r) = root {
            sums = r.as_ref().borrow().visit(0 as usize, sums);
        }
        let (mut max_level, mut max_value) = if sums.is_empty() {
            return 0;
        } else {
            (1, sums[0])
        };
        // let mut max_level = 0;
        // let mut max_value: i32 = 0;
        let mut cur_level = 0;
        for v in sums {
            cur_level = cur_level + 1;
            if max_value < v {
                max_value = v;
                max_level = cur_level;
            }
        }
        return max_level;
    }

    pub fn max_level_sum2(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut queue = VecDeque::new();
        // init max value(consider the max value may be negitive)
        let (mut cur_level_num, mut max_level, mut max_level_sum) = match root {
            Some(node) => {
                let cur_level_sum = node.as_ref().borrow().val;
                queue.push_back(node);
                (1, 1, cur_level_sum)
            }
            None => {
                return 0;
            }
        };
        let mut next_level_num = 0;
        let mut cur_level_sum = 0;
        let mut cur_level = 1;
        while let Some(node) = queue.pop_front() {
            cur_level_sum = cur_level_sum + node.as_ref().borrow().val;
            cur_level_num = cur_level_num - 1;
            if let Some(left) = node.as_ref().borrow().left.as_ref() {
                queue.push_back(left.clone());
                next_level_num = next_level_num + 1;
            }
            if let Some(right) = node.as_ref().borrow().right.as_ref() {
                queue.push_back(right.clone());
                next_level_num = next_level_num + 1;
            }
            // if cur level finished, reset the values.
            if cur_level_num == 0 {
                if cur_level_sum > max_level_sum {
                    max_level_sum = cur_level_sum;
                    max_level = cur_level;
                }
                cur_level = cur_level + 1;
                cur_level_num = next_level_num;
                cur_level_sum = 0;
                next_level_num = 0;
            }
        }
        return max_level;
    }

    pub fn max_level_sum3(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut queue = vec![];
        // init max value(consider the max value may be negitive)
        let (mut max_level, mut max_level_sum) = match root {
            Some(node) => {
                let cur_level_sum = node.as_ref().borrow().val;
                queue.push(node);
                (1, cur_level_sum)
            }
            None => {
                return 0;
            }
        };
        let mut cur_level = 1;
        while !queue.is_empty() {
            let mut next_level_nodes = vec![];
            let mut cur_level_sum = 0;
            for node in queue.drain(..) {
                cur_level_sum = cur_level_sum + node.as_ref().borrow().val;
                if let Some(left) = node.as_ref().borrow().left.as_ref() {
                    next_level_nodes.push(left.clone());
                }
                if let Some(right) = node.as_ref().borrow().right.as_ref() {
                    next_level_nodes.push(right.clone());
                }
            }
            if cur_level_sum > max_level_sum {
                max_level_sum = cur_level_sum;
                max_level = cur_level;
            }
            cur_level = cur_level + 1;
            queue = next_level_nodes;
        }
        return max_level;
    }
}

#[cfg(test)]
mod tests {
    use super::{Solution, TreeNode};
    #[test]
    fn test_max_level_sum() {
        let test_data = vec![
            (
                vec![Some(1), Some(7), Some(0), Some(7), Some(-8), None, None],
                2,
            ),
            (
                vec![
                    Some(989),
                    None,
                    Some(10250),
                    Some(98693),
                    Some(-89388),
                    None,
                    None,
                    None,
                    Some(-32127),
                ],
                2,
            ),
        ];
        for (vals, expect) in test_data {
            let root = TreeNode::build(vals);
            let max_level = Solution::max_level_sum3(root);
            assert_eq!(max_level, expect);
        }
    }
}
