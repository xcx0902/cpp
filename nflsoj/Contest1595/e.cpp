#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k, a, b, pos, mid, mxdep, len, ind, f[N], d[N], vis[N];
vector<int> g[N];

void dfs(int u, int fa) {
	for (int v: g[u]) 
        if (v != fa) {
            dfs(v, u);
            len = max(len, f[u] + f[v] + 1);
            f[u] = max(f[u], f[v] + 1);
	    }
}

void dfs1(int u, int fa, int dep) {
	if (dep > mxdep) {
		mxdep = dep;
		pos = u;
	}
	for (int v: g[u])
        if (v != fa)
            dfs1(v, u, dep + 1);
}

void dfs2(int u, int fa, int dep) {
	d[u] = dep;
	if (d[u] == len) {
		for (int k = 1; k <= n; k++)
			if (vis[k] && d[k] == len / 2) {
				mid = k;
				break;
			}
		return;
	}
	for (int v: g[u]) 
        if (v != fa) {
            vis[v] = 1;
            dfs2(v, u, dep + 1);
            vis[v] = 0;
	    }
}

void dfs3(int u, int fa, int dep) {
	d[u] = 1;
	for (int v: g[u]) 
        if (v != fa) {
            dfs3(v, u, dep + 1);
            d[u] = max(d[u], d[v] + 1) ;
        }
}

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
	    g[u].push_back(v);
	    g[v].push_back(u);
	}
	dfs(1, 0);
	dfs1(1, 0, 0);
	dfs2(pos, 0, 0);
	dfs3(mid, 0, 0);
	sort(d + 1, d + n + 1, cmp);
	cout << d[k + 1] << endl;;
	return 0;
}