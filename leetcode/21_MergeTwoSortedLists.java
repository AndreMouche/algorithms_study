/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
         ListNode cur=null;
         ListNode ans=null;
         if(l1==null){return l2;}
         if(l2==null){return l1;}
         if(l1.val<l2.val){
             ans=l1;
             l1=l1.next;
         }else {
             ans=l2;
             l2=l2.next;
         }
         cur = ans;
         while(l1!=null && l2!=null){
             if(l1.val<l2.val){
                cur.next = l1;
                l1=l1.next;
             } else {
                 cur.next=l2;
                 l2=l2.next;
             }
             cur=cur.next;
         }
         
          if(l1==null){
              cur.next=l2;
          }
        
          if(l2==null){
              cur.next=l1;
          }
        
         return ans;
    }
}
