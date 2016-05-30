package main

/**
 * Definition for a binary tree node.
 */
/**
https://leetcode.com/problems/binary-tree-level-order-traversal/
*/
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type NodeList struct {
	Node *TreeNode
	Next *NodeList
}

func NewNodeList() *NodeList {
	return &NodeList{
		Node: nil,
		Next: nil,
	}
}

type NodeQueue struct {
	Head *NodeList
	Tail *NodeList
}

func NewQueue() *NodeQueue {
	return &NodeQueue{
		Head: nil,
		Tail: nil,
	}
}

func (this *NodeQueue) IsEmpty() bool {
	return this.Head == nil
}

func (this *NodeQueue) Pop() *TreeNode {
	if this.Head == nil {
		return nil
	}
	node := this.Head
	this.Head = node.Next
	return node.Node
}

func (this *NodeQueue) Push(node *TreeNode) {
	nodeList := NewNodeList()
	nodeList.Node = node
	nodeList.Next = nil
	if this.Head == nil {
		this.Head = nodeList
		this.Tail = nodeList
		return
	}

	this.Tail.Next = nodeList
	this.Tail = nodeList
	return
}

func levelOrder(root *TreeNode) [][]int {
	ans := make([][]int, 0)
	if root == nil {
		return ans
	}

	qu := NewQueue()
	line := make([]int, 0)
	line = append(line, root.Val)

	root.Val = 1
	cur_levle := root.Val
	qu.Push(root)
	var node *TreeNode
	for node = qu.Pop(); node != nil; node = qu.Pop() {
		if node.Val == cur_levle {
			cur_levle += 1
			ans = append(ans, line)
			line = make([]int, 0)
		}
		if node.Left != nil {
			line = append(line, node.Left.Val)
			node.Left.Val = cur_levle
			qu.Push(node.Left)
		}
		if node.Right != nil {
			line = append(line, node.Right.Val)
			node.Right.Val = cur_levle
			qu.Push(node.Right)
		}
	}
	if len(line) > 0 {
		ans = append(ans, line)
	}
	return ans
}
