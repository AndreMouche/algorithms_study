package leetcode

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	total := 0
	for cur := head; cur != nil; cur = cur.Next {
		total++
	}
	if total < n {
		return head
	}

	total -= n

	if total == 0 {
		return head.Next
	}

	cur := head
	for ; total > 1; total-- {
		cur = cur.Next
	}
	cur.Next = cur.Next.Next
	return head
}
