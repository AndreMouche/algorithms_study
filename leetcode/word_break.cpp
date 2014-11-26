/*
 * https://oj.leetcode.com/problems/word-break/
 * 设计dp[]
 * dp[i]＝true 表示包括第i个字符在内的s前缀能由字典中的单词组成
 * 那么dp[0]=true;
 * dp[j] = f{dp[i-1]&dict.find(s.substr(i-1,j-i+1))}
 * j>=i
 * 中间有一个i满足条件即可
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
