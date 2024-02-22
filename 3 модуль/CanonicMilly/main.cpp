#include <iostream>
#include <vector>
#include <map>

using namespace std;

int ind = 0;

void dfs(int start, vector<int>& arr, vector<int>& positions, int m, vector<vector<int>>& in) {
    arr[start] = ind;
    positions[ind] = start;
    ind++;
    for (int i = 0; i < m; i++) {
        if (arr[in[start][i]] == -1) {
            dfs(in[start][i], arr, positions, m, in);
        }
    }
}

int main() {
    int n, m, q0;
    cin >> n >> m >> q0;

    vector<vector<int>> delta(n, vector<int>(m));
    vector<vector<string>> phi(n, vector<string>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> delta[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string signal;
            cin >> signal;
            phi[i][j] = signal;
        }
    }


    vector<int> positions(n);
    vector<int> arr(n, -1);
    ind = 0;

    dfs(q0, arr, positions, m, delta);


    cout << n << endl;
    cout << m << endl;
    cout << 0 << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[delta[positions[i]][j]] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << phi[positions[i]][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}