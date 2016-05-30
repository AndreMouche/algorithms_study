package main

/**
https://leetcode.com/problems/factorial-trailing-zeroes/
*/
import "fmt"

func trailingZeroes(n int) int {
	ans := 0
	for id := n / 5; id != 0; id = id / 5 {
		ans += id
	}
	return ans
}

func main3() {
	fmt.Println(trailingZeroes(200))
}
