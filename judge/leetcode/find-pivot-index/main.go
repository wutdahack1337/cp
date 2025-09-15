package main

func pivotIndex(nums []int) int {
	sum := 0
	for _, x := range nums {
		sum += x
	}

	presum := 0
	for idx, x := range nums {
		if sum-presum == presum+x {
			return idx
		}
		presum += x
	}

	return -1
}
