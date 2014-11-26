[word-break](http://oj.leetcode.com/problems/word-break/) 给定一个字典和字符串，判断该字符串能否由字典里面的多个单词组成。很明显的DP，定义一个bool型的DP，dp[i]＝true 表示包括第i个字符在内的s前缀能由字典中的单词组成。复杂度O（N^2)



