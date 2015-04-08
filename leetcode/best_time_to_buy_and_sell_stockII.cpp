/**
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
dp O(n)
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        for(int id = 1; id < prices.size(); id ++) {
            int cur = prices[id] - prices[id-1];
            if(cur > 0) {
                ans += cur;
            }
        }
        return ans;
    }
};
