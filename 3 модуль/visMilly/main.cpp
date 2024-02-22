#include <bits/stdc++.h>

using namespace std;

char alph[] = {'a', 'b', 'c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void printer(int v, int el, char ch, string r) {
    printf("\t%d -> %d [label = \"%c(", v, el, ch);
    cout << r << ")\"]\n";
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> delta(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            cin >> delta[i][j];
        }
    }
    vector<vector<string>> fi(n, vector<string>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            cin >> fi[i][j];
        }
    }
    queue<int> que;
    que.push(q);
    vector<bool> used(n, false);

    cout << "digraph {\n";
    cout << "\trankdir = LR\n";
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < m; i++) {
            if (!used[delta[v][i]]) {
                used[delta[v][i]] = true;
                que.push(delta[v][i]);
            }
            printer(v, delta[v][i], alph[i], fi[v][i]);
        }
    }
    cout << '}';
    return 0;
}