/**
 * https://oj.leetcode.com/problems/linked-list-cycle-ii/
 * 思路：
 * 设置两个指针s1,s2 = head
 * 第一个指针每次走1步
 * 第二个指针每次走2步
 * 再第一次相遇后，
 * */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            if(head == NULL) {
                return NULL;
            }
            ListNode *s1,*s2;
            s1 = head;
            s2 = head;
            int meet_s = 0;
            while(true) {
                meet_s += 1;
                if(s1 == NULL || s2 == NULL || s2->next == NULL) {
                    return NULL;
                }
                s1 = s1->next;
                s2 = s2->next->next;
                if(s1 == s2) {
                    break;
                }
            }

            int loopnum = 0;
            while(true) {
                loopnum += 1;
                if(s1 == NULL || s2 == NULL || s2->next == NULL) {
                    return NULL;
                }
                s1 = s1->next;
                s2 = s2->next->next;
                if(s1 == s2) {
                    break;
                }
            }

            int start_num = meet_s - loopnum ;
            s1 = head;
            for(int i = 0; i < start_num; i++) {
                s1 = s1->next;
            }

            while(true) {
                s2 = s1;
                for(int i = 0; i < loopnum;i++) {
                    s2 = s2->next;
                } 
                if (s1 == s2) {
                    return s1;
                }
                s1 = s1->next;
            }
        }
};
