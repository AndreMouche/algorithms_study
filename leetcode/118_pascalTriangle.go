package main

import "fmt"

/**
https://leetcode.com/problems/pascals-triangle/
*/
func generate(numRows int) [][]int {
	ans := make([][]int, numRows, numRows)
	for id := 0; id < numRows; id++ {
		ans[id] = make([]int, id+1, id+1)
		ans[id][0] = 1
		ans[id][id] = 1
		for j := 1; j <= id/2; j++ {
			ans[id][j] = ans[id-1][j] + ans[id-1][j-1]
			ans[id][id-j] = ans[id][j]
		}

	}
	return ans
}

func main() {
	ans := generate(5)
	fmt.Printf("%+v", ans)
}
