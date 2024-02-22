#include <iostream>
#include <vector>
using namespace std;

void add_edge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void count_bridges_util(vector<vector<int>>& graph, int u, vector<bool>& visited, vector<int>& parent, vector<int>& disc, vector<int>& low, int& bridge_count) {
    static int time = 0;

    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : graph[u]) {
        if (!visited[v]) {
            parent[v] = u;
            count_bridges_util(graph, v, visited, parent, disc, low, bridge_count);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) {
                bridge_count++;
            }
        }
        else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int count_bridges(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    vector<int> disc(n, 0);
    vector<int> low(n, 0);
    int bridge_count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count_bridges_util(graph, i, visited, parent, disc, low, bridge_count);
        }
    }

    return bridge_count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(graph, u, v);
    }

    int bridges = count_bridges(graph, n);
    cout << bridges << endl;

    return 0;
}