#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 300005;
int n, q, x, y, ans1, ans2, sum[N], f[N], p[N];
vector<int> g[N];

void dfs1(int u, int fa) {
    sum[u] = 1, f[u] = fa;
    for (int v: g[u])
        if (v != fa) {
            dfs1(v, u);
            sum[u] += sum[v];
        }
}

void dfs2(int u, int fa, int val) {
    p[u] = val;
    for (int v: g[u])
        if (v != fa)
            dfs2(v, u, val);
}

int isfa(int u, int v) {
    int tmp;
    while (v) {
        tmp = v, v = f[v];
        if (v == u) return tmp;
    }
    return 0;
    // return lst not u point
}

signed main() {
    scanf("%lld%lld", &n, &q);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%lld%lld", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    for (int v: g[1])
        dfs2(v, 1, v);
    while (q--) {
        scanf("%lld%lld", &x, &y);
        ans1 = n * (n - 1);
        if (n <= 3000) {
            if (isfa(x, y)) {
                ans1 -= (n - sum[isfa(x, y)]) * sum[y];
            } else if (isfa(y, x)) {
                ans1 -= (n - sum[isfa(y, x)]) * sum[x];
            } else {
                ans1 -= sum[x] * sum[y];
            }
        } else {
            ans1 -= (n - sum[p[y]]) * sum[y];
        }
        printf("%lld %lld\n", ans1, 0LL);
    }
    return 0;
}