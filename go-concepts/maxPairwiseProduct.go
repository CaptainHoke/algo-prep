package main

import (
	"errors"
	"fmt"
)

func maxPairwiseProduct(arr []int) int {
	firstMax, secondMax := -1, -1

	for _, e := range arr {
		if e > firstMax {
			secondMax = firstMax
			firstMax = e
		} else if e > secondMax {
			secondMax = e
		}
	}

	return firstMax * secondMax
}

func main() {
	arrSize := 0
	_, err := fmt.Scan(&arrSize)
	if err != nil {
		panic(errors.New("input's fucked"))
	}

	arr := make([]int, arrSize)
	for i := 0; i < arrSize; i++ {
		_, err := fmt.Scan(&arr[i])
		if err != nil {
			panic(errors.New("input's fucked"))
		}
	}

	fmt.Println(maxPairwiseProduct(arr))
}
