/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode node = head;
        ListNode pre = null;
        while(node!=null){
            ListNode next = node.next;
            node.next=pre;
            pre=node;
            if(next==null) {
                return node;
            }
            node=next;
        }
        return null;
    }
}
