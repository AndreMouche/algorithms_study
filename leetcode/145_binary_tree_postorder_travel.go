package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func postorderTraversal(root *TreeNode) []int {
	data := []int{}
	if root == nil {
		return data
	}
	if root.Left != nil {
		data = append(data, postorderTraversal(root.Left)...)
	}

	if root.Right != nil {
		data = append(data, postorderTraversal(root.Right)...)
	}

	data = append(data, root.Val)
	return data
}
