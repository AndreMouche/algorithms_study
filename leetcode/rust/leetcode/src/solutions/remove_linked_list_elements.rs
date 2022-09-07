// Definition for singly-linked list.
pub struct Solution;
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
    fn newvec(mut val: Vec<i32>) -> Option<Box<ListNode>> {
        if val.is_empty() {
            return None;
        }
        let mut head = ListNode::new(val[0]);
        head.next = ListNode::newvec(val[1..].into());
        Some(Box::new(head))
    }
}

impl Solution {
    /**
    https://leetcode.cn/problems/remove-linked-list-elements/
    简单题，用了递归
     */
    pub fn remove_elements(mut head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        while let Some(mut node) = head {
            if node.val == val {
                head = node.next.take();
            } else {
                node.next = Solution::remove_elements(node.next.take(), val);
                return Some(node);
            }
        }
        None
    }

    pub fn remove_elements1(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut new_head = if let Some(node) = head {
            node
        } else {
            return None;
        };
        while new_head.val == val {
            new_head = if let Some(node) = new_head.next {
                node
            } else {
                return None;
            };
        }
        let next = new_head.next.take();
        new_head.next = Solution::remove_elements(next, val);
        return Some(new_head);
    }
}

#[cfg(test)]
mod tests {
    // Import the necessary modules
    use super::ListNode;
    use super::Solution;
    #[test]
    fn test_link() {
        let test_data = vec![(vec![1, 2, 6, 3, 4, 5, 6], 6, vec![1, 2, 3, 4, 5])];
        for (data, val, expect) in test_data {
            let mut links = ListNode::newvec(data);
            let expectLink = ListNode::newvec(expect);
            let get = Solution::remove_elements(links, val);
            assert_eq!(get, expectLink);
        }
    }
}
