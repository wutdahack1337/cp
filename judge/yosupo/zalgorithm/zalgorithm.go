package main

import "fmt"

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func main() {
	var (
		str     string
		n, l, r int
		f       [500003]int
	)

	fmt.Scan(&str)
	n = len(str)

	f[0] = n
	l = -1
	r = -1
	for i := 1; i < n; i++ {
		if l < i && i <= r {
			if f[i-l] < r-i+1 {
				f[i] = f[i-l]
				continue
			}
		}
		l = i
		r = max(r, l)
		for r < n && str[r] == str[r-i] {
			r++
		}
		r--
		f[i] = r - l + 1
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d ", f[i])
	}
}
