#include <bits/stdc++.h>#define pb push_backusing namespace std;int main() {    int n, m;    cin >> n >> m;    vector<vector<int>> vec(n);    for (int i = 0; i < m; i++) {        int x, y;        cin >> x >> y;        vec[x].pb(y);        vec[y].pb(x);        }    int k; cin >> k;    vector<int> based(k);    for (int i = 0; i < k; i++) {        cin >> based[i];    }    vector<vector<int>> dists(k);    for (int i = 0; i < k; i++) {        vector<int> dist(n, n);        int s = based[i];        dist[s] = 0;        queue<int> q;        q.push(s);        while(!q.empty()) {            int v = q.front();            q.pop();            for (int u : vec[v]) {                if (dist[u] > dist[v] + 1) {                    dist[u] = dist[v] + 1;                    q.push(u);                }            }        }        dists[i] = dist;        /*for (int j : dist) {            cout << j << ' ';        }        cout << endl;*/    }    bool exists = false;    for (int i = 0; i < n; i++) {        int val = dists[0][i];        bool equal = true;        if (val == n)            equal = false;        for (int j = 1; j < k; j++) {            if (dists[j][i] != val) {                equal = false;                break;            }        }        if (equal) {            exists = true;            cout << i << ' ';        }    }    if (!exists)        cout << '-';    return 0;}