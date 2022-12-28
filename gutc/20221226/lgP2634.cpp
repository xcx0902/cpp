#include <bits/stdc++.h>
using namespace std;

const int N = 20005;
int n, cnt, rt, sum, ans, t[3], h[N], f[N], sz[N], d[N];
vector<pair<int, int>> g[N];
bool vis[N];

void getDep(int u, int fa) {
	t[d[u]]++;
	for (auto v: g[u]) 
        if (v.first != fa && !vis[v.first]) {
            d[v.first] = (d[u] + v.second) % 3;
            getDep(v.first, u);
        }
}

int calc(int u, int v) {
	t[0] = t[1] = t[2] = 0, d[u] = v;
	getDep(u, 0);
	return t[1] * t[2] * 2 + t[0] * t[0];
}

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

void solve(int u) {
	ans += calc(u, 0);
	vis[u] = 1;
	for (auto v: g[u])
        if (!vis[v.first]) {
            ans -= calc(v.first, v.second);
            rt = 0;
            sum = sz[v.first];
            getRoot(v.first, 0);
            solve(rt);
	    }
}

int main() {
	cin >> n;
	for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        w %= 3;
		g[u].push_back({v, w});
        g[v].push_back({u, w});
	}
	sum = f[0] = n;
	getRoot(1, 0);
	solve(rt);
	int g = __gcd(ans, n * n);
    cout << ans / g << "/" << n * n / g << endl;
	return 0;
}