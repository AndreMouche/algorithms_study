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


[Single number II](https://oj.leetcode.com/problems/single-number-ii/) 数据列表中除了一个数字只出现过一次外，其余都出现过三次，求只出现过一次的那个数字。
将数字转化为三进制对其后进行位运算加，各位对3取模即得答案。
注意：

* 中间结果会越int界。
* 处理负数时，需将int转换为long long 后再转，否则会越界。nt型的-2147483648转为正数会造成越界
*  int 范围-2147483648~2147483647

[clone-graph](https://oj.leetcode.com/problems/clone-graph/) 深拷贝一个地图结构
递归，使用map辅助

[palindrome-partitioning](https://oj.leetcode.com/problems/palindrome-partitioning/) 分割字符串并使得每个字串均为回文。算出所有分割方式。 回溯

[palindrome-partitioningII](https://oj.leetcode.com/problems/palindrome-partitioning-ii/) 求题1中最少分割次数。dp,O(n*n),dp[i]表示从sub[0,i]的最小分割次数，isPa[i][j]表示sub[i,j]是否是回文

[longest substring without repeating characters](https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/) 找出字符串中最长的无重复字符的字串。hash,设置左右指针。O(n)

[https://oj.leetcode.com/problems/surrounded-regions/](https://oj.leetcode.com/problems/surrounded-regions/) 找出被X包围的所有O，并将其置为X。BFS，对各个边上的O点进行bfs,未被 访问到的O点则为被包围的点。O(n*m)

[https://leetcode.com/problems/sum-root-to-leaf-numbers/](https://leetcode.com/problems/sum-root-to-leaf-numbers/) 深度优先搜索。
二叉树的每个节点值为0-9的数字，root到叶子节点的路径长定义为途中各个节点值排列后得到的数字。求该树所有叶子的路径和。


[https://leetcode.com/problems/longest-consecutive-sequence/](https://leetcode.com/problems/longest-consecutive-sequence/) 给一个未排序的整形数组，求排序后最大的连续数字长度，要求复杂度为O(n).  参考别人的用了map,O(nlogn)。达到O(n)的一种方法是使用unorderset,往两边边扫边从set中剔除元素。
<br>
[word-ladder](https://leetcode.com/problems/word-ladder/)两个字符串仅一个字符不一样则为相通。给你一个长度相等的startStr,endStr，一个相同长度的字符串集合dict,问startStr能否通过dict连通endStr,若能，则返回连通的字符串个数，包括首尾。若否，返回0.
<br>
看提示说是BFS，想当然的建图，算出个字符串间联通图，然后无耻的BFS，然后无限的TimeOut。。看了一下Discuss,瞬间被秒，大概思路是：从startStr开始，依次枚举变换该字符串的每个元素并将dict中存在的字符串放进下一解集，依次类推，直到遇到endStr...
<br>
经典的BFS题目。
想象一下，这个变换过程是一个树，每一层是当前所有的变换结果 ，下一层又是上一层的字符串的所有的变换结果。例子：
HIT
AIT, BIT, CIT, DIT.....     HAT, HBT, HCT, HDT.....    HIA, HIB, HIC, HID....

HIT 可以有这么多种变换方式，而AIT, BIT本身也可以以相同的方式展开，这就形成了一个相当大的树。
HIT
AIT, BIT, CIT, DIT.....     HAT, HBT, HCT, HDT.....    HIA, HIB, HIC, HID....
 |    (BIT,CIT这些没有再展开了，画图实在不方便)
 |
AIT, BIT, CIT, DIT...     ABT, ACT, ADT....

[网上比较好的解题报告](http://blog.sina.com.cn/s/blog_eb52001d0102v2ds.html)

[word-ladder-ii](https://leetcode.com/problems/word-ladder-ii/),求出上题最短连接串。思路与上题类似，多了一个回溯的过程。

[binary-tree-maximum-path-sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) 给出一颗二叉树，其中一条路径的值为该路径上所有节点值的和，求最大的路径值。dfs

[6. ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/) 简单的字符串操作
[338. Counting Bits](https://leetcode.com/problems/counting-bits/) 给一个数据n,求出0<=i<=num中i用二进制表示时1的个数

```  
     * 规律题
     * 0
     * 进位
     * 1 
     * 进位后
     * 10 11
     * 再进位后
     * 100 101 110 111 
     * 。。即每次进位后的1的个数，都是前面所有小于它的数字的1个数加1.以此类推即可
```

[337. House Robber III](https://leetcode.com/problems/house-robber-iii/) 简单递归，树

[65.Valid Number](https://leetcode.com/problems/valid-number/) 判断字符串是否为数字，模拟题，就是测试数据太变态，要很仔细很仔细才行。。

[68. Text Justification](https://leetcode.com/problems/text-justification/) 模拟题，细心即可。

[104.MaxDepthOfBinary.java](https://leetcode.com/problems/maximum-depth-of-binary-tree/) 求二叉树的树高，非递归解法&递归


[345. Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/) 简单题
[70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) 简单题，排列组合
[202.Happy Number](https://leetcode.com/problems/happy-number/) 简单题，模拟，检查循坏
[21.Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) 合并已排序链表
[24.Swap NOdes in pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) 简单链表操作
[198.House Robber](https://leetcode.com/problems/house-robber/) 简单动规a
[27.Remove Element](https://leetcode.com/problems/remove-element/) 简单模拟题
[110.Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/) 判断是否为平衡二叉树
[107.Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)简单题
[101.Symmetric Tree](https://leetcode.com/problems/symmetric-tree/) 简单模拟题 
[232.Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/) 两个栈实现一个队列
[66.Plus One](https://leetcode.com/problems/plus-one/) 简单模拟题，模拟十进制相加
[342.Power Of Four](https://leetcode.com/problems/power-of-four/) 简单题 
[118.Pascal's Trangle](https://leetcode.com/problems/pascals-triangle/) 简单题
