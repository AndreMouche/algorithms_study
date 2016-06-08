package main

/**
https://leetcode.com/problems/merge-sorted-array/
*/
func merge(nums1 []int, m int, nums2 []int, n int) {
	tail := m + n - 1
	t1 := m - 1
	t2 := n - 1
	for ; t1 >= 0 && t2 >= 0; tail-- {
		v1 := nums1[t1]
		v2 := nums2[t2]
		if v1 < v2 {
			nums1[tail] = v2
			t2--
		} else {
			nums1[tail] = v1
			t1--
		}
	}

	for ; t2 >= 0; tail-- {
		nums1[tail] = nums2[t2]
		t2--
	}
}

func main88() {

}
