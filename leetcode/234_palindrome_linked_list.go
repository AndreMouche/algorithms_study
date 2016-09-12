package main

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

//[1,2,3,1]
func isPalindrome(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return true
	}
	//找到中点
	s1, s2 := head, head.Next
	for (s2 != nil) && (s2.Next != nil) {
		s1, s2 = s1.Next, s2.Next.Next
	}
	var pre, cur *ListNode
	pre, cur = nil, s1.Next
	for cur != nil {
		next := cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}

	for s1, s2 = head, pre; s2 != nil; s1, s2 = s1.Next, s2.Next {
		if s1.Val != s2.Val {
			return false
		}
	}
	return true
}
