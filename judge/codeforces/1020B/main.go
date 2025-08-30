package main

import "fmt"

var (
	a       []int
	visited []bool
)

func DFS(u int) int {
	visited[u] = true

	if visited[a[u]] {
		return a[u]
	}

	return DFS(a[u])
}

func main() {
	var n int
	fmt.Scan(&n)

	a = make([]int, n+3)
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}

	visited = make([]bool, n+3)
	for u := 1; u <= n; u++ {
		for v := 1; v <= n; v++ {
			visited[v] = false
		}
		fmt.Printf("%d ", DFS(u))
	}
}
