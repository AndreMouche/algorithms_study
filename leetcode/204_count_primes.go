package main

import "fmt"

func countPrimes(n int) int {
	len := n/32 + 1 //用bitmap节省n-n/32的空间
	visited := make([]uint, len, len)
	ans := 0
	for id := 2; id < n; id++ {
		bit := uint(1) << uint(id%32)
		if (visited[id/32] & bit) > 0 {
			continue
		}
		//fmt.Println(id)
		ans++
		for j := id * id; j <= n; j += id {
			bit := uint(1) << uint(j%32)
			visited[j/32] |= bit
		}
	}
	return ans
}

func main204() {
	fmt.Println(countPrimes(10))
}
