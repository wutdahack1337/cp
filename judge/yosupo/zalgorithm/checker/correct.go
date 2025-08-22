package main

import "fmt"

func main() {
	var str string
	fmt.Scan(&str)

	n := len(str)

	for i := 0; i < n; i++ {
		it1 := i
		it2 := 0
		length := 0
		for it1 < n && str[it1] == str[it2] {
			length++
			it1++
			it2++
		}

		fmt.Printf("%d ", length)
	}
}
