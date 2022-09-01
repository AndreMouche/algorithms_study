pub struct Solution {}
impl Solution {
    /**
    https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/
    简单题，暴力
     */
    pub fn final_prices(prices: Vec<i32>) -> Vec<i32> {
        let mut discount = vec![0; prices.len()];
        let mut cur = 0;
        while cur < prices.len() {
            let mut start = cur + 1;
            while start < prices.len() && prices[start] > prices[cur] {
                start = start + 1;
            }
            if start < prices.len() {
                discount[cur] = prices[cur] - prices[start];
            } else {
                discount[cur] = prices[cur];
            }
            cur = cur + 1;
        }
        discount
    }
}
