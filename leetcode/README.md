[word-break](http://oj.leetcode.com/problems/word-break/) 给定一个字典和字符串，判断该字符串能否由字典里面的多个单词组成。很明显的DP，定义一个bool型的DP，dp[i]＝true 表示包括第i个字符在内的s前缀能由字典中的单词组成。复杂度O（N^2)

[word-break2](https://oj.leetcode.com/problems/word-break-ii/) 给定一个字典和字符串，判断该字符串能否由字典里面的多个单词组成,若能，请输出所有组合。与上题类似，但需要拿到组合就比较麻烦了。观察了下也就两种方法，要么开个大数组存储用dp存储每一步的数据，没有空间就用递归来解决。

[Copy List with Random Pointer](https://oj.leetcode.com/problems/copy-list-with-random-pointer/)
深拷贝一个带随机指针的单链表：

```
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

```

* 方法一：直接弄个map[old]=>copy的指针解决random问题，空间时间复杂度皆为O(n),其中需要额外消耗O(n)的空间存map.
* 方法二：巧妙省去map的开销：a->b->c这样的链表，每个元素后面插入一个前一个元素。a->A->b->B->c->C . 然后再设置A，B,C的random指针，最后把A->B->C这个链表剥离出来即可。