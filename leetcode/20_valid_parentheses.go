package main

import "fmt"

/**
https://leetcode.com/problems/valid-parentheses/
*/
func isValid(s string) bool {
	if len(s) == 0 || len(s)%2 == 1 {
		return len(s)%2 == 0
	}
	dict := map[uint8]uint8{
		'{': '}',
		'[': ']',
		'(': ')',
	}
	stack := make([]uint8, len(s)/2+1, len(s)/2+1)
	sid := -1
	for id := 0; id < len(s) && sid < len(s)/2; id++ {
		if sid == -1 {
			sid++
			stack[sid] = s[id]
			continue
		}
		v, ok := dict[stack[sid]]
		if !ok {
			return false
		}

		if v == s[id] {
			sid--
			continue
		}
		sid++
		stack[sid] = s[id]
	}
	//fmt.Println(sid)
	return sid == -1
}

func main() {
	fmt.Println(isValid("()[][()]"))
	fmt.Println(isValid("()"))
	fmt.Println(isValid("([[{}]])"))
	fmt.Println(isValid("([)]"))
	fmt.Println(isValid("["))

}
