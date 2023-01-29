#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005;

int n, t, s, e, cnt, g[N][N], ans[N][N], tmp[N][N];
map<int, int> mp;

void mul(int ans[N][N], int a[N][N], int b[N][N]) {
    memset(tmp, 0x3f, sizeof tmp);
    for (int k = 1; k <= cnt; k++)
        for (int i = 1; i <= cnt; i++)
            for (int j = 1; j <= cnt; j++)
                tmp[i][j] = min(tmp[i][j], a[i][k] + b[k][j]);
    memcpy(ans, tmp, sizeof tmp);
}

void solve() {
    memset(ans, 0x3f, sizeof ans);
    for (int i = 1; i <= cnt; i++)
        ans[i][i] = 0;
    while (n) {
        if (n & 1) mul(ans, ans, g);
        mul(g, g, g);
        n >>= 1;
    }
}

signed main() {
    cin >> n >> t >> s >> e;
    if (!mp.count(s)) mp[s] = ++cnt;
    if (!mp.count(e)) mp[e] = ++cnt;
    s = mp[s], e = mp[e];
    memset(g, 0x3f, sizeof g);
    while (t--) {
        int c, a, b;
        cin >> c >> a >> b;
        if (!mp.count(a)) mp[a] = ++cnt;
        if (!mp.count(b)) mp[b] = ++cnt;
        a = mp[a], b = mp[b];
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    solve();
    cout << ans[s][e] << endl;
    return 0;
}