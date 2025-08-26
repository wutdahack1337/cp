package main

import "fmt"

func main() {
	var k, n, w int
	fmt.Scanf("%d %d %d", &k, &n, &w)

	money := k * w * (w + 1) / 2
	fmt.Println(max(0, money-n))
}
