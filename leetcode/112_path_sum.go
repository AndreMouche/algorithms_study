package main

/**
https://leetcode.com/problems/path-sum/
*/
func hasPathSum(root *TreeNode, sum int) bool {
	if root == nil {
		return false
	}
	return checkSum(root, sum, 0)
}

func checkSum(root *TreeNode, sum, pre int) bool {
	if root == nil {
		return sum == pre
	}
	pre += root.Val

	if root.Left == nil && root.Right == nil {
		return pre == sum
	}

	if root.Left != nil && checkSum(root.Left, sum, pre) {
		return true
	}

	if root.Right != nil && checkSum(root.Right, sum, pre) {
		return true
	}
	return false
}
