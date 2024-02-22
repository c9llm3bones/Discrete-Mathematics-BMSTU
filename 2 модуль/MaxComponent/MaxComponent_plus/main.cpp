#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    vector<vector<int>> ans(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;y--;
        edges[x].pb(y);
        edges[y].pb(x);
    }


    return 0;
}
