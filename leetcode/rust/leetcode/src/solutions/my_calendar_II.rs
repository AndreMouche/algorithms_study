/**
 * https://leetcode.cn/problems/my-calendar-ii/solution/by-lfool-nodi/
 * 经典线段树模拟，注意细节处理，困了困了，不说太多了。
 */
struct Node {
    left: i32,
    right: i32,
    value: i32,
    children_value: i32,
    children: Vec<Box<Node>>,
}

impl Node {
    fn new(left: i32, right: i32, value: i32) -> Node {
        return Node {
            left: left,
            right: right,
            value: value,
            children: vec![],
            children_value: 0,
        };
    }

    fn cmp(&self, start: i32) -> std::cmp::Ordering {
        if self.left <= start {
            if start < self.right {
                return std::cmp::Ordering::Equal;
            }

            // start > self.right
            return std::cmp::Ordering::Less;
        }
        std::cmp::Ordering::Greater
    }

    // if overflow, return none, else return the max child's value
    fn check(&self, previous: i32, start: i32, end: i32) -> bool {
        if self.left >= end || self.right <= start {
            return true;
        }
        let cur_value = self.value + previous;
        if self.value + previous >= 2 {
            return false;
        }
        if self.total_value() + previous < 2 {
            return true;
        }
        // current node was part of [start,end)
        // start,self.left,self.right,end
        if self.left >= start && self.right <= end {
            return self.total_value() + previous <= 1;
        }
        let mut start_index = match self.children.binary_search_by(|child| child.cmp(start)) {
            Result::Ok(l) => {
                // child.left <= start < child.right
                if !self.children[l].check(cur_value, start, end) {
                    return false;
                }
                l + 1
            }
            // start<child.left
            Result::Err(l) => l,
        };

        // start node.left
        while let Some(node) = self.children.get(start_index) {
            start_index += 1;
            // end,node.left
            if end <= node.left {
                return true;
            }
            // node.left end node.right
            if end <= node.right {
                return node.check(cur_value, start, end);
            }
            //node.right,end
            if node.right <= end {
                if !node.check(cur_value, start, node.right) {
                    return false;
                }
            }
        }
        return true;
    }

    fn push_new_child(&mut self, idex: usize, node: Node) -> bool {
        if node.right > self.right || node.left < self.left || idex > self.children.len() {
            return false;
        }
        if node.total_value() > self.children_value {
            self.children_value = node.total_value()
        }
        self.children.insert(idex, Box::new(node));
        return true;
    }

    fn append_child(&mut self, node: Box<Node>) -> bool {
        if node.total_value() > self.children_value {
            self.children_value = node.total_value();
        }
        self.children.push(node);
        return true;
    }

    fn total_value(&self) -> i32 {
        self.children_value + self.value
    }

    // book and return the child's value.
    fn book(&mut self, mut start: i32, mut end: i32) -> i32 {
        if start < self.left {
            start = self.left;
        }
        if end > self.right {
            end = self.right;
        }
        // start self.left,self.right,end
        if self.left >= start && self.right <= end {
            self.value += 1;
            return self.total_value();
        }
        if self.children.is_empty() {
            let mut new_node = Node::new(start, end, 1);
            if new_node.left < self.left {
                new_node.left = self.left;
            }
            if new_node.right > self.right {
                new_node.right = self.right;
            }
            self.append_child(Box::new(new_node));
            return self.total_value();
        }
        let mut new_start = start;
        let start_index = match self.children.binary_search_by(|child| child.cmp(start)) {
            Result::Ok(l) => {
                // println!("ok{}",l);
                //node.left,start,node.right
                new_start = self.children[l].right;
                let child_value = self.children[l].book(start, end);
                // println!("book [{},{}] from [{},{}],subNodeValue:{}",start,end,self.children[l].left,self.children[l].right,child_value);
                if child_value > self.children_value {
                    self.children_value = child_value;
                }
                //node.left,start,end,node.right
                if new_start >= end {
                    return self.total_value();
                }
                l + 1
            }
            Result::Err(l) => {
                // println!("err{}",l);
                l
            }
        };

        let mut new_node = Node::new(new_start, end, 1);
        while let Some(node) = self.children.get(start_index) {
            //start,node.left,node.right,end
            if node.right <= end {
                let node = self.children.remove(start_index);
                new_node.right = node.right;
                new_node.append_child(node);
                continue;
            }
            // start node.left,end,node.right

            break;
        }

        match self.children.get(start_index) {
            None => {
                if new_node.right < end {
                    new_node.right = end;
                }
                new_start = new_node.right;
            }
            Some(node) => {
                // end node.left
                if end <= node.left {
                    new_node.right = end;
                    self.push_new_child(start_index, new_node);
                    return self.total_value();
                }

                // node.left,end
                if new_node.right > node.left {
                    new_node.right = node.left;
                }

                //book [node.left,end) from node.
                new_start = node.left;
            }
        }

        // println!("[{},{}]add new node[{},{})",self.left,self.right,new_node.left,new_node.right);

        // push new children
        self.push_new_child(start_index, new_node);
        // println!("new start,{},{}",new_start,end);
        if new_start < end {
            // println!("book{} [{},{}]",start_index+1, self.children[start_index + 1].left, self.children[start_index + 1].right);
            let child_value = self.children[start_index + 1].book(new_start, end);
            if child_value > self.children_value {
                self.children_value = child_value;
            }
        }
        return self.total_value();
    }

    fn outputTree(&self) {
        print!(
            "left:{},right:{},value {},children_value: {}\n",
            self.left, self.right, self.value, self.children_value
        );
        println!("children num {}", self.children.len());
        let mut idx = 0;
        while let Some(c) = self.children.get(idx) {
            print!("[{},{}]'s {} children ", self.left, self.right, idx);
            c.outputTree();
            println!();
            idx += 1;
        }
    }
}

struct MyCalendarTwo {
    tree: Node,
}

impl MyCalendarTwo {
    fn new() -> Self {
        MyCalendarTwo {
            tree: Node::new(0, i32::MAX, 0),
        }
    }

    fn book(&mut self, start: i32, end: i32) -> bool {
        if !self.tree.check(0, start, end) {
            return false;
        }
        self.tree.book(start, end);
        return true;
    }
}

#[cfg(test)]
mod tests {
    // Import the necessary modules
    use super::MyCalendarTwo;

    /**
     */
    #[test]
    fn test_book() {
        // let test_data = vec![
        //     ((10,20),true),
        //     ((50,60),true),
        //     ((10,40),true),
        //     ((5,15),false),
        //     ((5,10),true),
        //     ((25,55),true),
        // ];
        // let mut can = MyCalendarTwo::new();
        // for ((start,end), expect) in test_data {
        //     let got = can.book(start, end);
        //     assert_eq!(got, expect);
        // }

        let test_data = vec![
            // ((15,23),true),
            // ((10,18),true),
            // ((17,25),false),
            // ((8,17),false),
            ((21, 22), true),
            ((86, 87), true),
            ((71, 72), true),
            ((76, 77), true),
            ((50, 51), true),
            ((92, 93), true),
            ((99, 100), true),
            ((5, 6), true),
            ((71, 72), true),
            ((42, 43), true),
            ((72, 73), true),
            ((22, 23), true),
            ((51, 52), true),
            ((15, 16), true),
            ((70, 71), true),
            ((64, 65), true),
            ((57, 58), true),
            ((47, 48), true),
            ((4, 5), true),
            ((14, 15), true),
            ((2, 3), true),
            ((28, 29), true),
            ((35, 36), true),
            ((86, 87), true),
            ((72, 73), true),
            ((99, 100), true),
            ((50, 51), true),
        ];
        let mut can = MyCalendarTwo::new();
        for ((start, end), expect) in test_data {
            println!("start book {},{}", start, end);
            let got = can.book(start, end);
            can.tree.outputTree();
            println!("---------~~~~~~~~~~~~~~~~~~~------");

            assert_eq!(got, expect);
        }
    }
}
