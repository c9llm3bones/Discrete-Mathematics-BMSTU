package main

import (
	"fmt"
	"os"
	"sort"
)

type Group struct {
	a     int
	b     int
	val   int
	team1 []int
	team2 []int
}

func compare(a, b []int) bool {
	a_t := make([]int, len(a))
	b_t := make([]int, len(b))
	copy(a_t, a)
	copy(b_t, b)
	sort.Ints(a_t)
	sort.Ints(b_t)
	if len(a) > len(b) {
		return true
	} else if len(a) < len(b) {
		return false
	} else {
		u := 0
		for a_t[u] == b_t[u] {
			u++
		}
		return a_t[u] < b_t[u]
	}
}

func switchToFirst(D *Group) {
	sort.Ints(D.team1)
	sort.Ints(D.team2)
	if D.a < D.b {
		D.a, D.b = D.b, D.a
		D.team1, D.team2 = D.team1, D.team2
		D.val = D.a - D.b
	}
}

func dfs(graph [][]int, v int, used []int, color int, G *Group) {
	used[v] = color
	if color == 1 {
		G.team1 = append(G.team1, v)
		G.a++
		G.val++
	} else {
		G.team2 = append(G.team2, v)
		G.b++
		G.val--
	}
	new_color := 3 - color
	for i := 0; i < len(graph[v]); i++ {
		to := graph[v][i]
		if used[to] == -1 {
			dfs(graph, to, used, new_color, G)
		} else if used[to] != new_color {
			fmt.Println("No Solution")
			os.Exit(0)
		}
	}
}

func makeAllVars(team *[]Group, pos, num int, p, ans *[]int, n int) {
	if pos < num {
		var x, y []int
		for _, i := range (*team)[pos].team1 {
			x = append(x, i)
		}
		for _, i := range (*team)[pos].team2 {
			y = append(y, i)
		}
		for _, it := range x {
			*p = append(*p, it)
		}
		makeAllVars(team, pos+1, num, p, ans, n)
		for i := 0; i < len(x); i++ {
			*p = (*p)[:len(*p)-1]
		}
		for _, it := range y {
			*p = append(*p, it)
		}
		makeAllVars(team, pos+1, num, p, ans, n)
		for i := 0; i < len(y); i++ {
			*p = (*p)[:len(*p)-1]
		}
	} else {
		if 2*len(*p) <= n && compare(*p, *ans) {
			*ans = make([]int, len(*p))
			copy(*ans, *p)
		}
		return
	}
}
func main() {
	var n int
	fmt.Scanln(&n)
	graph := make([][]string, n)
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, 0)
	}

	for i := range graph {
		graph[i] = make([]string, n)
		for j := range graph[i] {
			fmt.Scan(&graph[i][j])
			if graph[i][j] == "+" {
				g[i] = append(g[i], j)
				g[j] = append(g[j], i)
			}

		}
	}
	used := make([]int, n)
	for i := range used {
		used[i] = -1
	}
	team := make([]Group, 0)
	for i := 0; i < n; i++ {
		if used[i] == -1 {
			G := Group{a: 0, b: 0, val: 0}
			dfs(g, i, used, 1, &G)
			team = append(team, G)
		}
	}
	num := len(team)

	for i := 0; i < num; i++ {
		switchToFirst(&team[i])
	}
	var ans []int
	var p []int
	makeAllVars(&team, 0, num, &p, &ans, n)
	sort.Ints(ans)
	for _, i := range ans {
		fmt.Print(i+1, " ")
	}

}
