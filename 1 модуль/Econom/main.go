package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var i = -1
var d = map[string]bool{}
var cnt = 0

func main() {

	expr := inserter()
	//fmt.Println(expr)
	result := Evaluate(expr)
	result += ""
	fmt.Println(cnt)
}

func Evaluate(expr []string) string {
	i++
	if i >= len(expr) {
		return ""
	}
	ch := expr[i]
	if isLetter(ch) {
		return ch
	}
	if isOp(ch) {
		ex := ch + Evaluate(expr) + Evaluate(expr)
		if !d[ex] {
			d[ex] = true
			cnt++
		}
		return ex
	}
	if ch == "(" {
		return Evaluate(expr)
	}
	if ch == ")" {
		return Evaluate(expr)
	}
	if ch == " " {
		return Evaluate(expr)
	}
	return ""
}

func isLetter(token string) bool {
	return token > "a" && token < "z"
}

func isOp(token string) bool {
	return token == "#" || token == "@" || token == "$"
}

func inserter() []string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str := scanner.Text()

	runes := strings.Split(str, "")
	return runes
}
