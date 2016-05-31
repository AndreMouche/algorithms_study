package leetcode

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

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	qu := NewQueue()
	root.Val = 1
	qu.Push(root)
	for node := qu.Pop(); node != nil; node = qu.Pop() {
		if node.Left == nil && node.Right == nil {
			return node.Val
		}
		if node.Left != nil {
			node.Left.Val = node.Val + 1
			qu.Push(node.Left)
		}

		if node.Right != nil {
			node.Right.Val = node.Val + 1
			qu.Push(node.Right)
		}
	}
	return -1
}
