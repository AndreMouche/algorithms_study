package main

/*
https://leetcode.com/problems/length-of-last-word/
*/

import (
	"fmt"
	"strings"
)

func lengthOfLastWord(s string) int {
	words := strings.Split(s, " ")
	id := len(words) - 1
	for ; id >= 0 && len(words[id]) == 0; id-- {

	}
	if id < 0 {
		return 0
	}
	return len(words[id])
}

func main58() {
	fmt.Println(lengthOfLastWord("Hello World"))
	fmt.Println(lengthOfLastWord(" "))
	fmt.Println(lengthOfLastWord("Hello "))
}
