struct Order {
    start: i32,
    end: i32,
}
impl Order {
    fn new(start: i32, end: i32) -> Order {
        return Order {
            start: start,
            end: end,
        };
    }
    fn compare(&self, start: i32) -> std::cmp::Ordering {
        if self.start <= start {
            if start < self.end {
                return std::cmp::Ordering::Equal;
            }
            return std::cmp::Ordering::Less;
        }
        return std::cmp::Ordering::Greater;
    }
}
struct MyCalendar {
    orders: Vec<Box<Order>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyCalendar {
    fn new() -> Self {
        MyCalendar { orders: vec![] }
    }
    /**
     * https://leetcode.cn/problems/my-calendar-i/submissions/
     * 简单题，对区间排序，二分查找，看是否存在重叠。
     */
    fn book(&mut self, start: i32, end: i32) -> bool {
        let next_order_id = match self.orders.binary_search_by(|order| order.compare(start)) {
            Result::Ok(_) => return false,
            Result::Err(l) => l,
        };
        match self.orders.get(next_order_id) {
            None => {}
            Some(order) => {
                // println!("next order [{},{}]",order.start,order.end);
                if order.start < end {
                    return false;
                }
            }
        }
        self.orders
            .insert(next_order_id, Box::new(Order::new(start, end)));
        return true;
    }
}

#[cfg(test)]
mod tests {
    // Import the necessary modules
    use super::MyCalendar;
    #[test]
    fn test_book() {
        let test_data = vec![
            ((10, 20), true),
            ((50, 60), true),
            ((10, 40), false),
            ((5, 15), false),
            ((5, 10), true),
            ((25, 55), false),
        ];
        let mut can = MyCalendar::new();
        for ((start, end), expect) in test_data {
            let got = can.book(start, end);
            println!("[{},{}] {}", start, end, got);
            assert_eq!(got, expect);
        }
    }
}
