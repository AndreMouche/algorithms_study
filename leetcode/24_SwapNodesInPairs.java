/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head==null||head.next==null){
            return head;
        }
        ListNode ans=head.next;
        ListNode pre=null;
        while(head!=null&&head.next!=null){
            ListNode next = head.next;
            head.next=next.next;
            next.next=head;
            if(pre!=null){
                pre.next=next;
            }
            pre=head;
            head=head.next;
        }
        return ans;
    }
}
