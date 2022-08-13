pub struct Solution {}

impl Solution {
    /*
    https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
     数组操作，简单题
    */
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut max_profit = 0;
        let mut min_price = 10000;
        for p in &prices {
            if *p < min_price {
                min_price = *p;
            } else {
                max_profit = max_profit.max(*p - min_price);
            }
        }
        max_profit
    }
}
