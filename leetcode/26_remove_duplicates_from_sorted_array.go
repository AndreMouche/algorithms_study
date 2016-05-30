package main

import "fmt"

/**
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/
func removeDuplicates(nums []int) int {
	if len(nums) <= 1 {
		return len(nums)
	}
	total := 0
	nums[total] = nums[0]
	for id := 1; id < len(nums); id++ {
		if nums[id] != nums[total] {
			total += 1
			nums[total] = nums[id]
		}
	}
	return total + 1
}

func main2() {
	fmt.Println(removeDuplicates([]int{1, 1, 2, 3, 4, 5}))
}
