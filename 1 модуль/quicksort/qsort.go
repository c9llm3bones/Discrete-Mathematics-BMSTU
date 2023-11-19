package main

import "fmt"

func qsort(arr []int, left int, right int) {
    if left >= right {
        return
    }
    pivot := partition(arr, left, right)
    qsort(arr, left, pivot-1)
    qsort(arr, pivot+1, right)
}

func partition(arr []int, left int, right int) int {
    pivot := arr[right]
    i := left
    for j := left; j < right; j++ {
        if arr[j] < pivot {
            arr[i], arr[j] = arr[j], arr[i]
            i++
        }
    }
    arr[i], arr[right] = arr[right], arr[i]
    return i
}

func main() {
    arr := []int{5, 2, 7, 1, 8, 3}
    qsort(arr, 0, len(arr)-1)
    fmt.Println(arr)
}
