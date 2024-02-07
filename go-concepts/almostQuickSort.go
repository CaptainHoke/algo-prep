package main

import (
	"fmt"
	"strings"
)

func almostQuickSort(arr []int) {
	almostQuickSortImpl(arr, 0, len(arr)-1)
}

// Ara-ara
func partition(arr []int, l int, r int) (left int, right int) {
	lt, curr, gt := l, l, r
	pivot := arr[l]

	for curr <= gt {
		switch {
		case arr[curr] < pivot:
			arr[curr], arr[lt] = arr[lt], arr[curr]
			curr++
			lt++
		case arr[curr] == pivot:
			curr++
		case arr[curr] > pivot:
			arr[curr], arr[gt] = arr[gt], arr[curr]
			gt--
		}
	}

	return lt, gt
}

func almostQuickSortImpl(arr []int, l int, r int) {
	if r <= l {
		return
	}

	midL, midR := partition(arr, l, r)

	almostQuickSortImpl(arr, l, midL-1)
	almostQuickSortImpl(arr, midR+1, r)
}

func main() {
	arrSize := 0
	_, err := fmt.Scan(&arrSize)
	if err != nil {
		panic(err)
	}

	arr := make([]int, arrSize)
	for i := 0; i < arrSize; i++ {
		_, err := fmt.Scan(&arr[i])
		if err != nil {
			panic(err)
		}
	}

	almostQuickSort(arr)

	fmt.Println(strings.Trim(fmt.Sprint(arr), "[]"))
}
