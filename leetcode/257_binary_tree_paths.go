package main

import (
	"fmt"
)

/*
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func binaryTreePaths(root *TreeNode) []string {
	ans := []string{}

	if root == nil {
		return ans
	}

	tails := binaryTreePaths(root.Left)
	tails = append(tails, binaryTreePaths(root.Right)...)

	if len(tails) == 0 {
		ans = append(ans, fmt.Sprintf("%d", root.Val))
		return ans
	}

	for _, v := range tails {
		ans = append(ans, fmt.Sprintf("%d->%s", root.Val, v))
	}
	return ans
}
