/*
 * https://oj.leetcode.com/problems/word-break/
 * 给定一个字典和字符串，判断该字符串能否由字典里面的多个单词组成。
 * 很明显的DP，定义一个bool型的DP
 * dp[i]＝true 表示包括第i个字符在内的s前缀能由字典中的单词组成。
 * 复杂度O（N^2)
 * */

class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            bool dp[500];
            int i,j;
            for(i = 0; i <= s.length(); i++) {
                dp[i]=false;
            }

            dp[0] = true;
            for(i=1; i <= s.length();i++) {
                if(dp[i-1]==false) {
                    continue;
                }
                for(j=i;j<=s.length();j++) {
                    if(dict.find(s.substr(i-1,j-i+1)) != dict.end()) {
                        dp[j] = true;
                    }
                }

                if(dp[s.length()]) {
                    return true;
                }

            }

            return false;
        }
};
