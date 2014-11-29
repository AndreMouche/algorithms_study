/**
* [Copy List with Random Pointer](https://oj.leetcode.com/problems/copy-list-with-random-pointer/)
* 深拷贝一个带随机指针的单链表：
* 方法一：直接弄个map[old]=>copy的指针解决random问题，
* 空间时间复杂度皆为O(n),其中需要额外消耗O(n)的空间存map.
 * */
#include <iostream>
#include <map>
using namespace std;
/**
 *  * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
    public:
        RandomListNode* copyRandomList(RandomListNode *head) {
            if(head == NULL) {
                return NULL;
            }

            map<RandomListNode*,RandomListNode*> old_new;
            RandomListNode* ansHead = new RandomListNode(head->label);
            old_new[head] = ansHead;
            ansHead->random = head->random;
            RandomListNode *pre = ansHead;
            for(RandomListNode *old = head->next;old != NULL;old=old->next){
                RandomListNode* cur = new RandomListNode(old->label);
                cur->random = old->random;
                pre->next = cur;
                old_new[old] = cur;
                pre = cur;
            }

            for(RandomListNode *cur = ansHead; cur != NULL; cur=cur->next) {
                cur->random = old_new[cur->random];
            }

            return ansHead;
        }
};

