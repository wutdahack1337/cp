package main

import "fmt"

func main() {
	var (
		record, winner string
		n_record       int
	)

	fmt.Scan(&record)
	n_record = len(record)

	aScore := 0
	bScore := 0
	tied := false
	for i := 0; i < n_record; i += 2 {
		who := string(record[i])
		score := int(record[i+1] - '0')
		if who == "A" {
			aScore += score
		} else {
			bScore += score
		}

		if aScore == 10 && bScore == 10 {
			tied = true
		}

		if (!tied && aScore >= 11) || (tied && aScore-bScore >= 2) {
			winner = "A"
			break
		} else if (!tied && bScore >= 11) || (tied && bScore-aScore >= 2) {
			winner = "B"
			break
		}
	}

	fmt.Println(winner)
}
