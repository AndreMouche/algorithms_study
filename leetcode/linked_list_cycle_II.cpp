/**
 * https://oj.leetcode.com/problems/linked-list-cycle-ii/
 * 思路：
 * 设置两个指针s1,s2 = head
 * 第一个指针每次走1步
 * 第二个指针每次走2步
 * 那么它们第一次相遇时，s1一定没有走完第一圈
 * 第二次相遇时，s2-s1的步数之差一定是环长的倍数，
 * 由于s1,s2走的步数决定了相遇位置一定是第一次相遇点，
 * 且一定是s1在第一次相遇后又走了一圈。
 * 假设第一次相遇耗时为t1,第二次相遇耗时为t2,环周长为s,则：
 * 2t1 = x + p
 * 2t1 = x + p + ks
 * 2t2 = x + p + s
 * st2 = x + p + (k+2)s
 * 这里x为环外的长度
 * p为相遇点到环起点位置的距离
 * 那么
 * 2t1-t1 = ks
 * 2t2-t2 = (k+1)s
 * 那么t2 - t1 = s
 * 在第一次相遇后到下一次s1走的步数一定为环的周长，即
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
