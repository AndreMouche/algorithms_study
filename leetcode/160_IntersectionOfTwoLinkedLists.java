package leetcode;


/**
 * https://leetcode.com/problems/intersection-of-two-linked-lists/
 * @author wuxuelian
 *
 * 将A的尾巴指向A的头
 * 从B出发，s1走一步，s2走两步，那么当它们走了a,2a步相遇时，
 * 假设x为B进入环之前的步数，y为它们相遇的点到B进入环的那个点的步数差，则
 * a ＝ x+y
 * 2a=x+y+len(A)
 * 那么len(A) = a,即圆的周长为走的步数a
 * 则 x=len(A)-y
 * 那么，此时s1从B的头出发，s2从当前点出发，两人走x步数之后会在B与A的交汇点集合
 */
public class IntersectionofTwoLinkedLists {
	  public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
		  if(headA==null || headB == null) {
			  return null;
		  }
		   ListNode tailA = headA;
		   while(tailA.next != null) {
			  tailA = tailA.next;
		   }

		   tailA.next = headA;
		   ListNode s1,s2;
		   s1=headB;
		   s2=headB;
		   boolean flag = false;
		   while(s1.next!=null && s2.next != null && s2.next.next != null&& !flag) {
			   s1 = s1.next;
			   s2 = s2.next.next;
			   flag = (s1 == s2);
		   }

		   if(!flag) {
			   tailA.next = null;
		       return null;
		   }
		   s1 = headB;
		   flag = false;
		   while(s1!=s2) {
			   s1 = s1.next;
			   s2 = s2.next;
		   }

		   tailA.next = null;
	       return s1;
	  }
}
