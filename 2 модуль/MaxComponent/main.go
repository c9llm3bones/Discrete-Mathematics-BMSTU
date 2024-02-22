package main

import (
	"fmt"
	"sort"
)

type Component struct {
	MinVertex  int
	Vertices   map[int]bool
	EdgesCount int
}

func dfs(v int, g [][]int, comp *Component, used []bool) {
	comp.Vertices[v] = true
	comp.EdgesCount += len(g[v])
	if comp.MinVertex > v {
		comp.MinVertex = v
	}
	used[v] = true
	for _, i := range g[v] {
		if !used[i] {
			dfs(i, g, comp, used)
		}
	}
}

func compare(a, b Component) bool {
	if len(a.Vertices) != len(b.Vertices) {
		return len(a.Vertices) > len(b.Vertices)
	}
	if a.EdgesCount != b.EdgesCount {
		return a.EdgesCount > b.EdgesCount
	}
	return a.MinVertex < b.MinVertex
}

func printGraph(g [][]int, edges []Edge, comp Component) {
	fmt.Println("graph {")
	for i := 0; i < len(g); i++ {
		fmt.Printf("\t%d", i)
		if comp.Vertices[i] {
			fmt.Print(" [color = red]")
		}
		fmt.Println()
	}
	for _, el := range edges {
		fmt.Printf("\t%d -- %d", el.From, el.To)
		if comp.Vertices[el.From] {
			fmt.Print(" [color = red]")
		}
		fmt.Println()
	}
	fmt.Println("}")
}

type Edge struct {
	From int
	To   int
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	g := make([][]int, n)
	edges := make([]Edge, m)
	for i := 0; i < m; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		edges[i] = Edge{x, y}
		g[x] = append(g[x], y)
		g[y] = append(g[y], x)
	}

	used := make([]bool, n)
	comps := make([]Component, 0)
	for i := 0; i < n; i++ {
		if !used[i] {
			comp := Component{
				MinVertex:  n + 2,
				Vertices:   make(map[int]bool),
				EdgesCount: 0,
			}
			dfs(i, g, &comp, used)
			comps = append(comps, comp)
		}
	}

	sort.Slice(comps, func(i, j int) bool {
		return !compare(comps[i], comps[j])
	})

	ans := comps[0]
	for i := 1; i < len(comps); i++ {
		if !compare(ans, comps[i]) {
			ans = comps[i]
		}
	}

	printGraph(g, edges, ans)
}
