package main

/**
https://leetcode.com/problems/count-and-say/
*/
import (
	"fmt"
	"strings"
)

func count(s string) string {
	//	fmt.Println("Origin:", s)
	if len(s) == 0 {
		return s
	}
	ans := []string{}
	num := 1
	cur := s[0]
	for id := 1; id < len(s); id++ {
		if s[id] == cur {
			num++
			continue
		}
		//	fmt.Println(cur, "number:", num)
		ans = append(ans, fmt.Sprintf("%d%c", num, cur))
		cur = s[id]
		num = 1
	}
	ans = append(ans, fmt.Sprintf("%d%c", num, cur))
	return strings.Join(ans, "")
}

func countAndSay(n int) string {
	if n < 1 {
		return "1"
	}
	s := "1"
	for id := 1; id < n; id++ {
		s = count(s)
	}
	return s
}

func main38() {
	for id := 1; id < 10; id++ {
		fmt.Println(countAndSay(id))
	}
}
