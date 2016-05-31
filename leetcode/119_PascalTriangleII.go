package main

import "fmt"

/**
https://leetcode.com/problems/pascals-triangle-ii/
*/
func getRow(rowIndex int) []int {
	ans := make([]int, rowIndex+1, rowIndex+1)
	for id := 0; id <= rowIndex; id++ {
		ans[id] = 1
	}
	for id := 0; id <= rowIndex; id++ {
		for j := id / 2; j >= 1; j-- {
			ans[j] = ans[j] + ans[j-1]
			ans[id-j] = ans[j]
		}
	}
	return ans
}

func main() {
	for id := 0; id <= 10; id++ {
		ans := getRow(id)
		fmt.Printf("%+v\n", ans)
	}
}
