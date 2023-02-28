#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200005;
int n, l, lg[N], dep[N], ans[N], fa[N][25], d[N][25];
vector<pair<int, int>> g[N];

int get(int u) {
    int dis = 0;
    for (int k = 20; k >= 0; k--) 
        while (fa[u][k] && dis + d[u][k] <= l)
            dis += d[u][k], u = fa[u][k];
    return u;
}

void collect(int u, int father) {
    for (auto v: g[u])
        if (v.first != father) {
            collect(v.first, u);
            ans[u] += ans[v.first];
        }
}

signed main() {
    cin >> n >> l;
    for (int i = 2; i <= n; i++) {
        cin >> fa[i][0] >> d[i][0];
        g[fa[i][0]].push_back({i, d[i][0]});
    }
	for (int i = 1; i <= 20; i++)
        for (int u = 1; u <= n; u++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
            d[u][i] = d[fa[u][i - 1]][i - 1] + d[u][i - 1];
        }
    for (int i = 1, t; i <= n; i++) {
        t = get(i);
        ans[i]++, ans[fa[t][0]]--;
    }
    // cerr << "d[3][1] = " << d[3][1] << endl;
    // for (int i = 0; i <= n; i++)
    //     cout << ans[i] << " ";
    // cout << endl;
    collect(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}
