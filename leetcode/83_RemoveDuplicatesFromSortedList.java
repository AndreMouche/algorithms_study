/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode cur=head;
        ListNode pre=head;
        while(cur!=null){
            pre = cur;
            while(cur.next!=null&&cur.val==cur.next.val){
                cur = cur.next;
            }
            cur=cur.next;
            pre.next=cur;
        }
        return head;
    }
}
