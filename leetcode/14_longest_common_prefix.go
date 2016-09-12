package main

import (
	"strings"
)

func longestCommonPrefix(strs []string) string {
	if len(strs) == 1 {
		return strs[0]
	}
	if len(strs) == 0 {
		return ""
	}
	ans := strs[0]
	for id := 1; id < len(strs); id++ {
		if strings.HasPrefix(ans, strs[id]) {
			ans = strs[id]
			continue
		}
		if strings.HasPrefix(strs[id], ans) {
			continue
		}
		for index, ch := range strs[id] {
			if rune(ans[index]) != ch {
				ans = ans[0:index]
				break
			}
		}
	}
	return ans
}

/*

／／求任意两个字符串的最长公共字串
type CharNode struct {
	sons map[rune]*CharNode
}

func longestCommonPrefix(strs []string) string {
	root := &CharNode{
		sons: make(map[rune]*CharNode),
	}
	ans := ""
	for _, str := range strs {
		curNode := root
		for id, ch := range str {
			_, ok := curNode.sons[ch]
			if !ok {
				curNode.sons[ch] = &CharNode{
					sons: make(map[rune]*CharNode),
				}
			} else {
				if id >= len(ans) {
					ans = str[0 : id+1]
				}
			}
			curNode = curNode.sons[ch]
		}
	}
	return ans
}

*/
