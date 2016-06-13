package main

import (
	"fmt"
)

func isIsomorphic(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	index := make(map[uint8]int)
	index2 := make(map[uint8]int)
	for id := 0; id < len(s); id++ {
		fid, ok := index[s[id]]
		fid2, ok2 := index2[t[id]]

		if !ok {
			fid = id
			index[s[id]] = id
		}

		if !ok2 {
			fid2 = id
			index2[t[id]] = id
		}

		//fmt.Println(fid, ok, fid2, ok, id)
		if fid != fid2 {
			return false
		}
	}
	return true
}

func main205() {
	fmt.Println(isIsomorphic("egg", "add"))
	fmt.Println(isIsomorphic("foo", "bar"))
	fmt.Println(isIsomorphic("paper", "title"))
	fmt.Println(isIsomorphic("", ""))
	fmt.Println(isIsomorphic("ab", "aa"))
	fmt.Println(isIsomorphic("bb", "aa"))
}
