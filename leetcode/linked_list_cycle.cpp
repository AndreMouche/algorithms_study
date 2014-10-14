/**
 * https://oj.leetcode.com/problems/linked-list-cycle/
 * 方法类似上一题：https://github.com/AndreMouche/algorithms_study/blob/master/leetcode/linked_list_cycle_II.cpp
 * 设置两个指针，第一个指针走1步，第二个指针每次走两步，若环存在，
 * 他们必将最后相交
 *
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
        bool hasCycle(ListNode *head) {
            if(head == NULL) {
                return false;
            }
            ListNode *s1,*s2;
            s1 = head;
            s2 = head;
            int meet_s = 0;
            while(true) {
                meet_s += 1;
                if(s1 == NULL || s2 == NULL || s2->next == NULL) {
                    return false;
                }
                s1 = s1->next;
                s2 = s2->next->next;
                if(s1 == s2) {
                    break;
                }
            }

           return true;
        }
};
