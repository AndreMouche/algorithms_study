package main

import "fmt"

/**
https://leetcode.com/problems/palindrome-number/
*/
func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	num := 1
	total := 1
	for tmp := x / 10; tmp != 0; tmp /= 10 {
		num += 1
		total *= 10
	}

	for cur := 1; cur < total; cur *= 10 {
		if (x/total)%10 != (x/cur)%10 {
			return false
		}
		total /= 10
	}
	return true
}

func main() {
	for id := 0; id < 120; id++ {
		fmt.Println(id, ":", isPalindrome(id))
	}
}
