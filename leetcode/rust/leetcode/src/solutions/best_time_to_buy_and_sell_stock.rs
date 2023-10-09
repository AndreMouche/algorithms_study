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

    /*
    https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
    Dynamic programming, the formula is as follows:
    with[idx] represents the maximum profit of holding stocks on day idx.
    without[idx] represents the highest profit of not holding stocks on day idx.
    with[idx] = std::cmp::max(with[idx-1], without[idx-2]-price);
    without[idx] = std::cmp::max(without[idx-1], with[idx-1]+price);
     */
    pub fn maxProfitWithCooldown2(prices: Vec<i32>) -> i32 {
        if prices.is_empty() {
            return 0;
        }
        let mut with = vec![0; prices.len()];
        let mut without = vec![0; prices.len()];
        for (idx, price) in prices.iter().enumerate() {
            //println!("{},{}",idx,price);
            if idx == 0 {
                with[idx] = -price;
                continue;
            }
            let pre_with_out = if idx == 1 { 0 } else { without[idx - 2] };
            with[idx] = std::cmp::max(with[idx - 1], pre_with_out - price);
            without[idx] = std::cmp::max(without[idx - 1], with[idx - 1] + price);
        }
        *without.last().unwrap()
    }

    /*
    https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
    Optimize the previous solution in terms of memory, as can be seen from the dynamic programming formula，
    we only need to keep the data of the past three days, we can use a rolling array to reduce memory usage.
     */
    pub fn maxProfitWithCooldown(prices: Vec<i32>) -> i32 {
        if prices.is_empty() {
            return 0;
        }
        let mut with = vec![0; 3];
        let mut without = vec![0; 3];
        for (idx, price) in prices.iter().enumerate() {
            //println!("{},{}",idx,price);
            if idx == 0 {
                with[idx % 3] = -price;
                continue;
            }
            let pre_with_out = if idx == 1 { 0 } else { without[(idx - 2) % 3] };
            with[idx % 3] = std::cmp::max(with[(idx - 1) % 3], pre_with_out - price);
            without[idx % 3] = std::cmp::max(without[(idx - 1) % 3], with[(idx - 1) % 3] + price);
        }
        without[(prices.len() - 1) % 3]
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    #[test]
    fn test_with_cooldown() {
        let test_cases = vec![(vec![1, 2, 3, 0, 2], 3), (vec![1], 0), (vec![2, 1, 4], 3)];

        for (prices, profit) in test_cases {
            let got = Solution::maxProfitWithCooldown(prices);
            assert_eq!(got, profit);
        }
    }
}
