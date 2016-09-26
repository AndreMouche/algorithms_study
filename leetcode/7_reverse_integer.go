package main

func reverse(x int) int {
	if x-int(int32(x)) > 0 {
		return 0
	}
	flag := 1
	ans := x % 10
	if x < 0 {
		x = -x
		ans = x % 10
		flag = -1
	}

	x = x / 10
	for ; x > 0; x = x / 10 {
		ans = ans*10 + x%10
		if ans != int(int32(ans)) { //已越界
			return 0
		}
	}
	ans = ans * flag
	if ans != int(int32(ans)) { //已越界
		return 0
	}
	return ans
}
