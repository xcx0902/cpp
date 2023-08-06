#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
int n, m, ans, ind[N], w[N], f[N][30], st[N], a[N];
vector<int> g[N];
queue<int> q;
string s;

bool topo() {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!ind[i])
            q.push(i);
    while (q.size()) {
        int u = q.front(); q.pop();
        a[++cnt] = u;
        for (int v: g[u])
            if (--ind[v] == 0)
                q.push(v);
    }
    return cnt == n;
}

int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        w[i] = s[i - 1] - 'a';
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        ind[v]++;
    }
    for (int i = 1; i <= n; i++)
        if (!ind[i])
            f[i][w[i]] = 1;
    if (!topo()) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) 
        for (int j: g[a[i]])
            for (int k = 0; k < 26; k++)
                f[j][k] = max(f[j][k], f[a[i]][k] + (w[j] == k));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            ans = max(ans, f[i][j]);
    cout << ans << endl;
    return 0;
}