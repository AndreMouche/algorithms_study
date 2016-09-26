package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	data := []int{}
	if root.Left != nil {
		data = append(data, inorderTraversal(root.Left)...)
	}
	data = append(data, root.Val)
	if root.Right != nil {
		data = append(data, inorderTraversal(root.Right)...)
	}
	return data
}
