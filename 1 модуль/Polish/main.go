package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var i = -1
var stack = []int{}

func main() {
	expr := inserter()
	//fmt.Println(expr)
	result := Evaluate(expr)
	fmt.Printf("%d", result)
}

func Evaluate(expr []string) int {
	i++
	if i >= len(expr) {
		return 0
	}
	ch := expr[i]
	if isNumber(ch) {
		ans, _ := strconv.Atoi(ch)
		return ans
	}
	if ch == "(" {
		return Evaluate(expr)
	}
	if ch == ")" {
		return Evaluate(expr)
	}
	if ch == "*" {
		return Evaluate(expr) * Evaluate(expr)
	}
	if ch == "+" {
		return Evaluate(expr) + Evaluate(expr)
	}
	if ch == "-" {
		return Evaluate(expr) - Evaluate(expr)
	}
	if ch == " " {
		return Evaluate(expr)
	}
	return 0
	/*
		var stack []int
		tokens := reverse(expr)
		fmt.Println(tokens)
		for _, token := range tokens {
			if token == "(" || token == ")" {
				continue
			} else if isNumber(token) {
				number, _ := strconv.Atoi(token)
				stack = append(stack, number)
			} else {
				b := stack[len(stack)-1]
				a := stack[len(stack)-2]
				stack = stack[:len(stack)-2]
				if token == "+" {
					stack = append(stack, a+b)
				}
				if token == "-" {
					stack = append(stack, b-a)
				}
				if token == "*" {
					stack = append(stack, a*b)
				}
			}
		}*/

}

func isNumber(token string) bool {
	_, err := strconv.Atoi(token)
	return err == nil
}
func reverse(arr []string) []string {
	for i, j := 0, len(arr)-1; i < len(arr)/2; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
	return arr
}
func inserter() []string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str := scanner.Text()

	runes := strings.Split(str, "")
	return runes
}
