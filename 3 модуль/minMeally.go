package main

import (
	"fmt"
	"math/rand"
)

type Automat struct {
	n, m, q int
	one     [][]int
	two     [][]string
	oneNew  [][]int
	twoNew  [][]string
}

func NewAutomat(n, m, q int, one [][]int, two [][]string) *Automat {
	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, m)
	}
	b := make([][]string, n)
	for i := range b {
		b[i] = make([]string, m)
	}
	return &Automat{
		n:      n,
		m:      m,
		q:      q,
		one:    one,
		two:    two,
		oneNew: a,
		twoNew: b,
	}
}

func (a *Automat) DFS(used []int, begin int, index *int) {
	used[begin] = *index
	*index++
	for i := 0; i < a.m; i++ {
		if used[a.one[begin][i]] == -1 {
			a.DFS(used, a.one[begin][i], index)
		}
	}
}

func (a *Automat) Canon() {
	used := make([]int, a.n)
	for i := range used {
		used[i] = -1
	}
	index := 0
	a.DFS(used, a.q, &index)
	for i := 0; i < a.n; i++ {
		if used[i] != -1 {
			a.twoNew[used[i]] = a.two[i]
			for j := 0; j < a.m; j++ {
				a.oneNew[used[i]][j] = used[a.one[i][j]]
			}
		}
	}
	a.n = index
	a.one = a.oneNew
	a.two = a.twoNew
}

func (a *Automat) Find(x int, parent []int) int {
	if parent[x] == x {
		return x
	} else {
		parent[x] = a.Find(parent[x], parent)
		return parent[x]
	}
}

func (a *Automat) Union(x, y int, parent []int) {
	xNew := a.Find(x, parent)
	yNew := a.Find(y, parent)
	if xNew == yNew {
		return
	}
	if rand.Intn(2) == 0 {
		xNew, yNew = yNew, xNew
	}
	parent[xNew] = yNew
}

func (a *Automat) Split(m *int, help []int) {
	*m = a.n
	parent := make([]int, *m)
	for i := 0; i < *m; i++ {
		parent[i] = i
	}
	for i := 0; i < a.n; i++ {
		for j := i + 1; j < a.n; j++ {
			if help[i] == help[j] && a.Find(i, parent) != a.Find(j, parent) {
				eq := true
				for k := 0; k < a.m; k++ {
					if help[a.one[i][k]] != help[a.one[j][k]] {
						eq = false
						break
					}
				}
				if eq {
					a.Union(i, j, parent)
					*m--
				}
			}
		}
	}
	for i := 0; i < a.n; i++ {
		help[i] = a.Find(i, parent)
	}
}

func (a *Automat) Split1(q *int, help []int) {
	*q = a.n
	parent := make([]int, *q)
	for i := 0; i < *q; i++ {
		parent[i] = i
	}
	for i := 0; i < a.n; i++ {
		for j := i + 1; j < a.n; j++ {
			if a.Find(i, parent) != a.Find(j, parent) {
				eq := true
				for k := 0; k < a.m; k++ {
					if a.two[i][k] != a.two[j][k] {
						eq = false
						break
					}
				}
				if eq {
					a.Union(i, j, parent)
					*q--
				}
			}
		}
	}
	for i := 0; i < a.n; i++ {
		help[i] = a.Find(i, parent)
	}
}

func (a *Automat) AufenkampHohn() {
	help := make([]int, a.n)
	var m1, m2 int
	a.Split1(&m1, help)
	for m1 != m2 {
		m2 = m1
		a.Split(&m1, help)
	}
	help1 := make([]int, a.n)
	help2 := make([]int, a.n)
	n := a.n
	for i, a := 0, 0; i < n; i++ {
		if help[i] == i {
			help2[a] = i
			help1[i] = a
			a++
		}
	}
	a.n = m1
	a.q = help1[help[a.q]]
	p := make([][]string, a.n)
	for i := range p {
		p[i] = make([]string, a.m)
	}
	for i := 0; i < a.n; i++ {
		for j := 0; j < a.m; j++ {
			a.one[i][j] = help1[help[a.one[help2[i]][j]]]
			p[i][j] = a.two[help2[i]][j]
		}
	}
	a.two = p
}

func (a *Automat) Print() {
	fmt.Printf("digraph {\n\trankdir = LR\n")

	for i := 0; i < a.n; i++ {
		for j := 0; j < a.m; j++ {
			fmt.Printf("\t%d -> %d [label = \"%c(%s)\"]\n", i, a.one[i][j], 97+j, a.two[i][j])
		}
	}
	fmt.Printf("}")
}

func main() {
	var n, m, q int
	fmt.Scan(&n, &m, &q)
	one := make([][]int, n)
	for i := range one {
		one[i] = make([]int, m)
		for j := range one[i] {
			fmt.Scan(&one[i][j])
		}
	}
	two := make([][]string, n)
	for i := range two {
		two[i] = make([]string, m)
		for j := range two[i] {
			fmt.Scan(&two[i][j])
		}
	}
	mealy := NewAutomat(n, m, q, one, two)
	mealy.AufenkampHohn()
	mealy.Canon()
	mealy.Print()
}
