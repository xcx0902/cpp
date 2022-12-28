#include <bits/stdc++.h>
using namespace std;

const int N = 200005, INF = 0x3f3f3f3f;
int n, k, sum, rt, ans = INF, cnt, lst, sz[N], f[N], a[N], b[N], t[N];
vector<pair<int, int>> g[N];
bool vis[N];

void getRoot(int u, int fa) {
	sz[u] = 1, f[u] = 0;
	for (auto v: g[u])
		if (v.first != fa && !vis[v.first]) {
			getRoot(v.first, u);
			sz[u] += sz[v.first];
			f[u] = max(f[u], sz[v.first]);
		}
	f[u] = max(f[u], sum - sz[u]);
	if (f[u] < f[rt]) rt = u;
}

void init(int u, int fa, int dis, int w) {
	if (dis > k) return;
	a[++cnt] = dis, b[cnt] = w;
	for (auto v: g[u])
        if (v.first != fa && !vis[v.first])
            init(v.first, u, dis + v.second, w + 1);
}

void calc(int u) {
	t[0] = cnt = lst = 0;
	for (auto v: g[u])
		if (!vis[v.first]) {
			cnt = lst;
			init(v.first, u, v.second, 1);
			for (int i = lst + 1; i <= cnt; i++)
                ans = min(ans, t[k - a[i]] + b[i]);
			for (int i = lst + 1; i <= cnt; i++)
                t[a[i]] = min(t[a[i]], b[i]);
			lst = cnt;
		}
	for (int i = 1; i <= cnt; i++)
        t[a[i]] = INF;
}

void dfs(int u) {
	calc(u);
	vis[u] = 1;
	for (auto v: g[u])
		if (!vis[v.first]) {
			rt = 0;
			sum = sz[v.first];
			getRoot(v.first, 0);
			dfs(rt);
		}
}

int main() {
	cin >> n >> k;
	for (int i = 1, u, v, w; i < n; i++) {
		cin >> u >> v >> w;
        u++, v++;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
	}
	f[0] = INF, sum = n;
	memset(t, 0x3f, sizeof t);
	getRoot(1, 0);
	dfs(rt);
	if (ans != INF) cout << ans << endl;
	else cout << -1 << endl;
    return 0;
}