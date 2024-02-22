package main

import (
	"fmt"
	"math"
	"sort"
)

func isPrime(x int64) bool {
	for i := int64(2); i < int64(math.Sqrt(float64(x)))+1; i++ {
		if x%i == 0 && x != i {
			return false
		}
	}
	return true
}
func printDot(x int64, edges map[int64][]int64) {
	fmt.Println("graph {")
	var sortedKeys []int64
	for k := range edges {
		sortedKeys = append(sortedKeys, k)
	}
	sort.Slice(sortedKeys, func(i, j int) bool { return sortedKeys[i] > sortedKeys[j] })
	for _, k := range sortedKeys {
		fmt.Printf("\t%d\n", k)
	}
	fmt.Printf("\t%d\n", 1)
	printedEdges := make(map[string]bool)
	for _, k := range sortedKeys {
		for _, v := range edges[k] {
			edgeStr := fmt.Sprintf("%d--%d", k, v)
			if _, ok := printedEdges[edgeStr]; !ok {
				fmt.Printf("\t%s\n", edgeStr)
				printedEdges[edgeStr] = true
			}
		}
	}
	fmt.Println("}")
}

func factorize(x int64, edges map[int64][]int64) {
	if isPrime(x) && x != 1 {
		edges[x] = []int64{1}
	} else if x == int64(4) {
		edges[x] = []int64{2}
		factorize(int64(2), edges)
	} else {
		for i := int64(2); i < int64(math.Sqrt(float64(x)))+2; i++ {
			if x%i == 0 {
				if isPrime(i) {
					edges[x] = append(edges[x], x/i)
				}
				factorize(x/i, edges)
				if isPrime(x / i) {
					edges[x] = append(edges[x], x/(x/i))
					factorize(x/(x/i), edges)
				}
			}
		}
	}
}

func main() {
	var x int64
	fmt.Scan(&x)
	edges := make(map[int64][]int64)
	factorize(x, edges)
	printDot(x, edges)
}
