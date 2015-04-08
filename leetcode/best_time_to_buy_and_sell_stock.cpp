/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * dp o(n)
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        int pre = 0;
        for(int id=1;id < prices.size(); id ++) {
            int cur = prices[id]-prices[id-1];
            if(pre > 0) {
                cur += pre;
            }
            
            if(cur>ans) ans = cur;
            pre = cur;
        }
        return ans;
    }
};
