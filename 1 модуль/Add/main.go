package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	/*var p int
	fmt.Scanln(&p)

	a := inserter()
	b := inserter()*/
	a := []int32{1, 2, 3}
	b := []int32{4, 5, 6}
	fmt.Println(add(a, b, 10))
}

func add(a, b []int32, p int) []int32 {

	output := []int32{}
	ost := 0
	minLen := min(len(a), len(b))

	for i := 0; i < minLen; i++ {
		output = append(output, int32((int(a[i])+int(b[i])+ost)%p))
		ost = (int(a[i]) + int(b[i]) + ost) / p
	}

	for _, slice := range [][]int32{a, b} {
		if len(slice) > minLen {
			for i := minLen; i < len(slice); i++ {
				output = append(output, int32((int(slice[i])+ost)%p))
				ost = (int(slice[i]) + ost) / p
			}
		}
	}

	if ost != 0 {
		output = append(output, int32(ost%p))
	}

	return output

}

func min(i int, i2 int) int {
	if i < i2 {
		return i
	}
	return i2
}

func inserter() []int32 {
	arr := []int32{}

	reader := bufio.NewReader(os.Stdin)

	input, err := reader.ReadString('\n')

	if err != nil {
		fmt.Println("Ошибка чтения ввода:", err)
	}

	for _, str := range strings.Fields(input) {
		num, err := strconv.ParseInt(str, 10, 32)
		if err != nil {
			fmt.Println("Ошибка преобразования строки в число:", err)
			continue
		}
		arr = append(arr, int32(num))
	}

	return arr
}

func reverse(arr []int32) []int32 {
	for i, j := 0, len(arr)-1; i < len(arr)/2; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
	return arr
}
