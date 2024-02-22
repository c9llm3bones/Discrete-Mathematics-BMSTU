#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define pb push_back

using namespace std;

double dest(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {

    int n;
    cin >> n;
    vector<pair<int, int>> verticles(n);
    vector<pair<double, pair<int, int>>> g;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        verticles[i] = make_pair(x, y);

    }

    for (int i = 0; i < n; i++) {
        pair<int, int> v = verticles[i];
        for (int j = i + 1; j < n; j++) {
            double d = dest(v.first, v.second, verticles[j].first, verticles[j].second);
            g.pb({d, {i, j}});
        }
    }
    vector<pair<pair<int, int>, pair<int, int>>> res;

    sort(g.begin(), g.end());
    vector<int> tree_id(n);

    for (int i = 0; i < n; ++i)
        tree_id[i] = i;

    int m = g.size();
    double cost = 0;

    for (int i = 0; i < m; ++i) {
        int a = g[i].second.first, b = g[i].second.second;
        double l = g[i].first;
        if (tree_id[a] != tree_id[b]) {
            cost += l;
            int old_id = tree_id[b], new_id = tree_id[a];
            for (int j = 0; j < n; ++j)
                if (tree_id[j] == old_id)
                    tree_id[j] = new_id;
        }
    }
    printf("%.2f\n", cost);

    return 0;

}