#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, len;
};

int Prim(int n, vector<Edge> edges) {
    vector<vector<pair<int, int>>> adj(n);
    for (const auto& edge : edges) {
        adj[edge.u].push_back({edge.v, edge.len});
        adj[edge.v].push_back({edge.u, edge.len});
    }
    vector<bool> used(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int totalLength = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int len = pq.top().first;
        pq.pop();

        if (used[u]) {
            continue;
        }

        used[u] = true;
        totalLength += len;

        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int edgeLen = neighbor.second;
            if (!used[v]) {
                pq.push({edgeLen, v});
            }
        }
    }
    return totalLength;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int x, y, len;
        cin >> x >> y >> len;
        edges[i].u = x;
        edges[i].v = y;
        edges[i].len = len;
    }

    int ans = Prim(n, edges);
    cout << ans;
    return 0;
}