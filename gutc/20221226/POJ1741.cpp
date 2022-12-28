#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 10005, INF = 0x3f3f3f3f;
int n, k, ans, tot, rt, tsz, cnt, sz[N], w[N], tmp[N];
vector<pii> g[N];
bool vis[N];

void getRoot(int u, int f) {
	sz[u] = 1;
	w[u] = 0;
	for (pii v: g[u])
		if (v.first != f && !vis[v.first]) {
			getRoot(v.first, u);
			sz[u] += sz[v.first];
			w[u] = max(w[u], sz[v.first]);
		}
	w[u] = max(w[u], tsz - sz[u]);
	if (w[rt] > w[u]) rt = u;
}

void getTmp(int u, int d, int f) {
	tmp[++cnt] = d;
	for (pii v: g[u])
		if (v.first != f && !vis[v.first])
			getTmp(v.first, d + v.second, u);
}

int calc(int u, int d) {
	cnt = 0;
	getTmp(u, d, 0);
	int l = 1, r = cnt, ret = 0;
	sort(tmp + 1, tmp + cnt + 1);
	while (l <= r) {
		while (r > 0 && tmp[l] + tmp[r] > k)
			r--;
		if (l > r) break;
		ret += r - l + 1;
		l++;
	}
	return ret;
}

void dfs(int u) {
	ans += calc(u, 0);
	vis[u] = 1;
	for (pii v: g[u])
		if (!vis[v.first]) {
			ans -= calc(v.first, v.second);
			rt = 0, tsz = sz[v.first];
			getRoot(v.first, 0);
			dfs(rt);
		}
}

int main() {
	while (cin >> n >> k && n && k) {
		tot = ans = rt = 0; w[0] = INF; tsz = n;
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i++)
			g[i].clear();
		for (int i = 1, u, v, w; i < n; i++) {
			cin >> u >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		getRoot(1, 0);
		dfs(rt);
		cout << ans - n << endl;
	}
	return 0;
}
