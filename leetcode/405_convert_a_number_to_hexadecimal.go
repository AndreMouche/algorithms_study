package main

import (
	"fmt"
)

func toHex(num int) string {
	if num == 0 {
		return "0"
	}
	fifteen := 15
	data := make([]int, 8, 8)
	id := 0
	for ; num != 0 && id < 8; id++ {
		data[id] = num & fifteen
		//fmt.Println("data id num", id, data[id], num)
		num = num >> 4
	}
	ans := ""
	for id = id - 1; id >= 0; id-- {
		if data[id] >= 10 {
			ans = fmt.Sprintf("%s%c", ans, data[id]-10+'a')
		} else {
			ans = fmt.Sprintf("%s%d", ans, data[id])
		}
	}
	return ans
}

func main() {
	fmt.Println("10:", toHex(10))
	fmt.Println("-1", toHex(-1))
	fmt.Println("-2", toHex(-2))
}
