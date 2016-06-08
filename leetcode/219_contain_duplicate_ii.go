package main

import (
	"fmt"
)

/**
https://leetcode.com/problems/contains-duplicate-ii/
*/
func containsNearbyDuplicate(nums []int, k int) bool {
	mp := make(map[int]bool)

	for id, v := range nums {
		if id > k {
			pre := nums[id-k-1]
			delete(mp, pre)
			//fmt.Printf("%+v(%+v):%+v\n", id, v, mp)
		}
		_, ok := mp[v]
		if ok {
			return true
		}
		mp[v] = true
	}
	return false
}

func main219() {
	nums := []int{1, 2, 1}
	fmt.Println(containsNearbyDuplicate(nums, 1))
}
