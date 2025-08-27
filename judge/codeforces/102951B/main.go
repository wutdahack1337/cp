package main

import "fmt"

func main() {
	var (
		n, x int
		a    [105]int
	)

	fmt.Scan(&n, &x)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if a[i] > a[j] {
				tmp := a[i]
				a[i] = a[j]
				a[j] = tmp
			}
		}
	}

	ans := 0
	for i := 0; i < n; i++ {
		if x >= a[i] {
			ans++
			x -= a[i]
		}
	}

	fmt.Println(ans)
}
