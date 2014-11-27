[word-break](http://oj.leetcode.com/problems/word-break/) 给定一个字典和字符串，判断该字符串能否由字典里面的多个单词组成。很明显的DP，定义一个bool型的DP，dp[i]＝true 表示包括第i个字符在内的s前缀能由字典中的单词组成。复杂度O（N^2)

[word-break2](https://oj.leetcode.com/problems/word-break-ii/) 给定一个字典和字符串，判断该字符串能否由字典里面的多个单词组成,若能，请输出所有组合。与上题类似，但需要拿到组合就比较麻烦了。观察了下也就两种方法，要么开个大数组存储用dp存储每一步的数据，没有空间就用递归来解决。
