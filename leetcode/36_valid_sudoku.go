package main

/**
https://leetcode.com/problems/valid-sudoku/
*/
func checkLittleBox(board [][]byte, sx, sy int) bool {
	m := make(map[byte]bool)
	for id := sx + 2; id >= sx; id-- {
		for j := sy + 2; j >= sy; j-- {
			if board[id][j] == '.' {
				continue
			}
			_, ok := m[board[id][j]]
			if ok {
				return false
			}
			m[board[id][j]] = true
		}
	}
	return true
}

func checkLineX(board [][]byte, s int) bool {
	m := make(map[byte]bool)
	for id := 0; id < 9; id++ {
		if board[s][id] == '.' {
			continue
		}
		_, ok := m[board[s][id]]
		if ok {
			return false
		}
		m[board[s][id]] = true
	}
	return true
}

func checkLineY(board [][]byte, s int) bool {
	m := make(map[byte]bool)
	for id := 0; id < 9; id++ {
		if board[id][s] == '.' {
			continue
		}
		_, ok := m[board[id][s]]
		if ok {
			return false
		}
		m[board[id][s]] = true
	}
	return true
}

func isValidSudoku(board [][]byte) bool {
	for id := 0; id < 3; id++ {
		for j := 0; j < 3; j++ {
			if !checkLittleBox(board, id*3, j*3) {
				return false
			}
		}
	}

	for id := 0; id < 9; id++ {
		if !checkLineX(board, id) || !checkLineY(board, id) {
			return false
		}
	}

	return true
}
