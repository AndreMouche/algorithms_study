package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isLeaf(root *TreeNode) bool {
	if root == nil {
		return false
	}
	if root.Left == nil && root.Right == nil {
		return true
	}
	return false
}

func sumOfLeftLeaves(root *TreeNode) int {
	if root == nil {
		return 0
	}
	ans := 0
	if isLeaf(root.Left) {
		ans = root.Left.Val
	} else {
		ans = sumOfLeftLeaves(root.Left)
	}

	ans += sumOfLeftLeaves(root.Right)

	return ans

}
