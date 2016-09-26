package main

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func preorderTraversal(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	data := []int{root.Val}

	if root.Left != nil {
		data = append(data, preorderTraversal(root.Left)...)
	}
	if root.Right != nil {
		data = append(data, preorderTraversal(root.Right)...)
	}
	return data
}
