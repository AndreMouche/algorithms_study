/**
[Copy List with Random Pointer](https://oj.leetcode.com/problems/copy-list-with-random-pointer/)
 深拷贝一个带随机指针的单链表：
方法二：巧妙省去map的开销：a->b->c这样的链表，每个元素后面插入一个前一个元素。
a->A->b->B->c->C . 然后再设置A，B,C的random指针，最后把A->B->C这个链表剥离出来即可。
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
            for(RandomListNode *cur = head; cur!=NULL;) {
               RandomListNode *copy = new RandomListNode(cur->label);
               copy->next = cur->next;
               cur->next = copy;
               cur = copy->next;
            }

            for(RandomListNode *cur = head;cur != NULL;) {
               RandomListNode *copy = cur->next;
               if(cur->random == NULL) {
                  copy->random = NULL;
               } else {
                  copy->random = cur->random->next;
               }

               cur = copy->next;
            }

            RandomListNode *ans = head->next;
            RandomListNode *copy = ans;
            head->next = copy->next;
            for(RandomListNode *cur = head->next;cur != NULL;) {
                  copy->next = cur->next;
                  copy = cur->next;
                  cur->next = copy->next;
                  cur = cur->next;
            }

            return ans;
        }
};

