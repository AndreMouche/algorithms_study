package leetcode

func strStr(haystack string, needle string) int {
	next := GetNextSlice(needle)
	nid, id := 0, 0
	for ; id < len(haystack) && nid < len(needle); id++ {
		for (haystack[id] != needle[nid]) && nid > 0 {
			nid = next[nid]
		}
		if haystack[id] == needle[nid] {
			nid++
			continue
		}
	}
	if nid == len(needle) {
		return id - nid
	} else {
		return -1
	}

}

/**
计算next数组
next[i]为neele[i-1]的前缀和后缀的最大公共串长度
*/
func GetNextSlice(needle string) []int {
	next := make([]int, len(needle), len(needle))
	for id := 0; id < len(needle); id++ {
		pre := id - 1
		for pre > 0 && needle[next[pre]] != needle[id-1] {
			pre = next[pre]
		}
		if pre <= 0 {
			next[id] = 0
		} else {
			next[id] = next[pre] + 1
		}
	}
	return next
}
