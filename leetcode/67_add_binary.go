package main

import (
	"fmt"
)

func addBinary(a string, b string) string {
	num := len(a)
	if num < len(b) {
		num = len(b)
	}
	ans := make([]int, num+1, num+1)
	index := 0
	for ai, bi := len(a)-1, len(b)-1; ai >= 0 || bi >= 0; {
		tmp := ans[index]
		if ai >= 0 && a[ai] == '1' {
			tmp += 1
		}
		if bi >= 0 && b[bi] == '1' {
			tmp += 1
		}
		ans[index] = tmp & 1
		ans[index+1] = tmp >> 1
		//	fmt.Println(index, tmp, ans[index], ans[index+1])
		index++
		ai--
		bi--
	}

	for index = num; ans[index] == 0 && index > 0; index-- {
	}
	ansStr := ""
	for ; index >= 0; index-- {
		ansStr = fmt.Sprintf("%s%d", ansStr, ans[index])
	}
	return ansStr
}

func main() {
	fmt.Println(addBinary("10", "11"))
	//	fmt.Println(addBinary("10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101", "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011"))
}
