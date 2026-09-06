package main

import (
	"fmt"
	"slices"
)

func Abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func threeSumClosest(nums []int, target int) int {

	l := len(nums)
	slices.Sort(nums)
	var ss = 30001
	var res int

	for i := range l {
		m := i + 1
		n := l - 1

		for m < n {
			sum := nums[m] + nums[n] + nums[i]
			if sum == target {
				return target
			} else if sum < target {
				if target-sum < ss {
					res = sum
					ss = target - res
				}
				m++
			} else {
				if sum-target < ss {
					res = sum
					ss = res - target
				}
				n--
			}
		}
	}

	return res
}
func main() {
	fmt.Println(threeSumClosest([]int{-1, 2, -1, 4}, 1))
	fmt.Println(threeSumClosest([]int{0, 0, 0}, 1))
	fmt.Println(threeSumClosest([]int{1, 1, -1}, 1))
	fmt.Println(threeSumClosest([]int{-1, 2, 1, -4}, 1))
	fmt.Println(threeSumClosest([]int{-1000, -1000, -1000}, 1000))
	// -4 -1 1 2
}
