package main

import (
	"fmt"
	"math/rand"
)

type Automat struct {
	n        int
	m        int
	q        int
	delta    [][]int
	phi      [][]string
	deltaNew [][]int
	twdeltaw [][]string
}

func NewAutomat(n, m, q int) *Automat {
	automat := &Automat{
		n:        n,
		m:        m,
		q:        q,
		delta:    make([][]int, n),
		phi:      make([][]string, n),
		deltaNew: make([][]int, n),
		twdeltaw: make([][]string, n),
	}
	for i := 0; i < n; i++ {
		automat.delta[i] = make([]int, m)
		automat.phi[i] = make([]string, m)
		automat.deltaNew[i] = make([]int, m)
		automat.twdeltaw[i] = make([]string, m)
	}
	return automat
}

func (a *Automat) DFS(used []int, begin int, index *int) {
	used[begin] = *index
	(*index)++
	for i := 0; i < a.m; i++ {
		if used[a.delta[begin][i]] == -1 {
			a.DFS(used, a.delta[begin][i], index)
		}
	}
}

func (a *Automat) Canon() {
	used := make([]int, a.n)
	for i := 0; i < a.n; i++ {
		used[i] = -1
	}
	index := 0
	a.DFS(used, a.q, &index)
	for i := 0; i < a.n; i++ {
		if used[i] != -1 {
			a.twdeltaw[used[i]] = make([]string, a.m)
			copy(a.twdeltaw[used[i]], a.phi[i])
			for j := 0; j < a.m; j++ {
				a.deltaNew[used[i]][j] = used[a.delta[i][j]]
			}
		}
	}
	a.q = 0
	a.n = index
	a.delta = a.deltaNew
	a.phi = a.twdeltaw
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
					if help[a.delta[i][k]] != help[a.delta[j][k]] {
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
					if a.phi[i][k] != a.phi[j][k] {
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
			a.delta[i][j] = help1[help[a.delta[help2[i]][j]]]
			p[i][j] = a.phi[help2[i]][j]
		}
	}
	a.phi = p
}

func (a *Automat) Scan() {
	for i := 0; i < a.n; i++ {
		for j := 0; j < a.m; j++ {
			fmt.Scan(&a.delta[i][j])
		}
	}
	for i := 0; i < a.n; i++ {
		for j := 0; j < a.m; j++ {
			fmt.Scan(&a.phi[i][j])
		}
	}
}

func (a *Automat) Eq(mealy *Automat) bool {
	if a.n != mealy.n || a.m != mealy.m || a.q != mealy.q {
		return false
	}
	for i := 0; i < a.n; i++ {
		for j := 0; j < a.m; j++ {
			if a.delta[i][j] != mealy.delta[i][j] || a.phi[i][j] != mealy.phi[i][j] {
				return false
			}
		}
	}
	return true
}

func main() {
	var n, m, q int
	fmt.Scan(&n, &m, &q)

	mealy1 := NewAutomat(n, m, q)
	mealy1.Scan()
	mealy1.AufenkampHohn()
	mealy1.Canon()

	fmt.Scan(&n, &m, &q)

	mealy2 := NewAutomat(n, m, q)
	mealy2.Scan()
	mealy2.AufenkampHohn()
	mealy2.Canon()

	if mealy1.Eq(mealy2) {
		fmt.Println("EQUAL")
	} else {
		fmt.Println("NOT EQUAL")
	}
}
