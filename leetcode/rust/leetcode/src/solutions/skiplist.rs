use std::cell::RefCell;
use std::rc::Rc;
type LinkNode = Rc<RefCell<Node>>;

const MAX_LEVEL: usize = 10;
struct Node {
    key: i32,
    next: Option<LinkNode>,
    down: Option<LinkNode>,
}

impl Node {
    fn init(key: i32, level: usize) -> LinkNode {
        let mut cur_level = 1;
        let mut down: Option<LinkNode> = None;
        loop {
            let node = Node {
                key: key,
                next: None,
                down: down,
            };
            if cur_level == level {
                return Rc::new(RefCell::new(node));
            }
            down = Some(Rc::new(RefCell::new(node)));
            cur_level = cur_level + 1;
        }
    }
}

struct Skiplist {
    root: LinkNode,
}

impl Skiplist {
    fn new() -> Self {
        Skiplist {
            root: Node::init(-1, MAX_LEVEL),
        }
    }

    //find the previous node <=target
    fn find(&self, target: i32) -> Vec<LinkNode> {
        let mut nodes = vec![];
        let mut node_opt = Some(self.root.clone());
        while let Some(node) = node_opt {
            if node
                .borrow()
                .next
                .clone()
                .filter(|n| n.borrow().key <= target)
                .is_some()
            {
                node_opt = node.borrow().next.clone();
                continue;
            }
            //current is the larget node <=target
            nodes.push(node.clone());
            node_opt = node.borrow().down.clone();
        }
        return nodes;
    }

    fn search(&self, target: i32) -> bool {
        // check the buttom level's max node with value <= target
        self.find(target)
            .last()
            .filter(|n| n.borrow().key == target)
            .is_some()
    }

    fn add(&mut self, num: i32) {
        let mut previous_nodes = self.find(num);
        let mut previous_down = None;
        // 1. make sure the num are always in the buttom level.
        // 2. the level of the current num are rand.
        // 3. the highest level is the MAX-LEVEL
        while (previous_down.is_none() || rand::random()) && !previous_nodes.is_empty() {
            let prev_left = previous_nodes.pop().unwrap();
            let num_node = Node {
                key: num,
                next: prev_left.borrow().next.clone(),
                down: previous_down,
            };
            previous_down = Some(Rc::new(RefCell::new(num_node)));
            prev_left.borrow_mut().next = previous_down.clone();
        }
    }

    fn erase(&self, num: i32) -> bool {
        let mut prevous_nodes = self.find(num - 1);
        let mut exist = false;
        while !prevous_nodes.is_empty() {
            let prev_left = prevous_nodes.pop().unwrap();
            let next = match prev_left.borrow().next.clone() {
                None => {
                    return exist;
                }
                Some(n) => {
                    let next = n.borrow();
                    if next.key == num {
                        exist = true;
                        // should remove
                        next.next.clone()
                    } else {
                        return exist;
                    }
                }
            };
            prev_left.borrow_mut().next = next;
        }
        return exist;
    }
}

#[cfg(test)]
mod tests {
    // Import the necessary modules
    use super::Skiplist;
    /**
     * skip list 知道概念直接模拟开搞就行。
      https://leetcode.cn/problems/design-skiplist
    */
    #[test]
    fn test_skiplist() {
        let mut skiplist = Skiplist::new();
        skiplist.add(5);
        skiplist.add(1);
        skiplist.add(15);
        skiplist.add(1);
        skiplist.add(2);
        skiplist.add(3);
        assert_eq!(skiplist.search(0), false);
        skiplist.add(4);
        assert_eq!(skiplist.search(1), true); // 返回 true
        assert_eq!(skiplist.erase(0), false); // 返回 false，0 不在跳表中
        assert_eq!(skiplist.erase(1), true); // 返回 true
        assert_eq!(skiplist.search(1), true); // 返回 true, 还有 1 个
        assert_eq!(skiplist.erase(1), true); // 返回 true
        assert_eq!(skiplist.search(1), false); // 返回 false，meihou了
    }
}
