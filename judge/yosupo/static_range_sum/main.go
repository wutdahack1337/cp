package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	reader *bufio.Reader = bufio.NewReader(os.Stdin)
	writer *bufio.Writer = bufio.NewWriter(os.Stdout)
)

func scan(a ...interface{})             { fmt.Fscan(reader, a...) }
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }

func main() {
	defer writer.Flush()

	var (
		n, q, l, r int
		a          []int
		f          []int64
	)

	scan(&n, &q)

	a = make([]int, n+3)
	f = make([]int64, n+3)
	for i := 0; i < n; i++ {
		scan(&a[i])
		f[i+1] = f[i] + int64(a[i])
	}

	for i := 0; i < q; i++ {
		scan(&l, &r)
		printf("%d\n", f[r]-f[l])
	}
}
