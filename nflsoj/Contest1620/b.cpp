#include <bits/stdc++.h>
using namespace std;

int n, m, k, c[100001];
vector<pair<int, int>> g[1001];
priority_queue<int> q[1001];

int main() {
    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    q[1].push(0);
    for (int u = 1; u <= n; u++)
        for (auto v: g[u]) {
            for (int t = 1; t <= k; t++) {
                if (q[v.first].empty()) break;
                q[u].push(q[v.first].top() - v.second);
                c[++c[0]] = q[v.first].top();
                q[v.first].pop();
            }
            for (int t = 1; t <= c[0]; t++)
                q[v.first].push(c[t]);
            c[0] = 0;
        }
    for (int i = 1; i <= k; i++)
        if (q[n].empty())
            cout << -1 << endl;
        else {
            cout << -q[n].top() << endl;
            q[n].pop();
        }
    return 0;
}