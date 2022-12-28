#include <bits/stdc++.h>
using namespace std;

const int N = 10001, K = 10000001;
int n, m, sum, rt, cnt, sz[N], a[N], f[N], vis[N], ans[K], dep[N], tmp[N];
vector<pair<int, int>> g[N];

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

void getDis(int u, int dis, int fa) {
	tmp[++cnt] = dis;
	for (auto v: g[u]) 
        if (v.first != fa && !vis[v.first]) 
            getDis(v.first, dis + v.second, u);
}

void change(int u, int dis, int w) {
	cnt = 0;
	getDis(u, dis, 0);
	for (int i = 1; i <= cnt; i++)
		for (int j = 1; j <= cnt; j++)
			if (i != j)
				ans[tmp[i] + tmp[j]] += w;
}

void calc(int u) {
	change(u, 0, 1);
	vis[u] = 1;
	for (auto v: g[u]) 
        if (!vis[v.first]) {
            change(v.first, v.second, -1);
            sum = sz[u], rt = 0, f[0] = n;
            getRoot(v.first, u);
            calc(rt);
        }
}

int main() {
	cin >> n >> m;
	for (int i = 1, u, v, w; i < n; i++) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
        g[v].push_back({u, w});
	}
	sum = f[0] = n;
	getRoot(1, 0);
	calc(rt);
	for (int i = 1, k; i <= m; i++) {
		cin >> k;
        cout << ((ans[k])? "AYE" : "NAY") << endl;
	}
	return 0;
}