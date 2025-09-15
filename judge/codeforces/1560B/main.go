package main

import "fmt"

func Solve() int {
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	if a > b {
		tmp := a
		a = b
		b = tmp
	}

	left := b - a + 1 - 2
	total := 2*left + 2
	if b > total || c > total {
		return -1
	}

	return (c+left)%total + 1
}

func main() {
	var t int
	fmt.Scan(&t)
	for t > 0 {
		fmt.Println(Solve())
		t--
	}
}
