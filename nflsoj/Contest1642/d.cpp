#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 205;
int n, m, cnt, isNULL = 1, ind[N], mk[N], edge[N][N];
vector<pair<int, int>> ans, g[N];
queue<int> q;
__int128 c[N], u[N];

void topo() {
    for (int i = 1; i <= n; i++)
        if (ind[i] == 0)
            q.push(i), mk[i] = 1;
    while (q.size()) {
        int x = q.front(); q.pop();
        if (!mk[x]) {
            c[x] -= u[x];
            mk[x] = 1;
        }
        if (g[x].size() == 0)
            ans.push_back({x, c[x]});
        for (auto y: g[x]) {
            if (c[x] > 0) c[y.first] += (__int128)y.second * c[x];
            if (!mk[y.first]) {
                c[y.first] -= u[y.first];
                mk[y.first] = 1;
            }
            ind[y.first]--;
            if (ind[y.first] == 0) {
                if (c[y.first] < 0) c[y.first] = 0;
                q.push(y.first);
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        c[i] = x, u[i] = y;
    }
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        if (u == v || edge[u][v]) continue;
        edge[u][v];
        g[u].push_back({v, w});
        ind[v]++;
    }
    topo();
    sort(ans.begin(), ans.end());
    for (auto p: ans)
        if (p.second > 0)
            cout << p.first << " " << p.second << endl, isNULL = 0;
    if (isNULL)
        cout << "NULL" << endl;
    return 0;
}