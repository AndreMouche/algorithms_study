package main

/**
https://leetcode.com/problems/remove-linked-list-elements/
 * Definition for singly-linked list.
*/

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeElements(head *ListNode, val int) *ListNode {
	for ; head != nil; head = head.Next {
		if head.Val != val {
			break
		}
	}

	for cur := head; cur != nil && cur.Next != nil; {
		if cur.Next.Val == val {
			cur.Next = cur.Next.Next
		} else {
			cur = cur.Next
		}
	}
	return head
}

func main_203() {
	node := &ListNode{
		Val:  1,
		Next: nil,
	}
	node.Next = &ListNode{
		Val:  2,
		Next: nil,
	}

	removeElements(node, 2)
}
