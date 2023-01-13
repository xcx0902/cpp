#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005, M = 505;

int n, m, ans, s, cnt, tot = 1;
int a[N], q[N], w[N], bl[N], tr[M][N], st[M], ed[M], sz[M];
bool d[N];

void add(int t, int x, int w) {
	for (int i = x; i <= n; i += (i & (-i)))
		tr[t][i] += w;
}

int query(int t, int x) {
	int ans = 0;
	for (int i = x; i >= 1; i -= (i & (-i)))
		ans += tr[t][i];
	return ans;
}

signed main() {
	cin >> n >> m;
	s = sqrt(n);
	st[1] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		w[a[i]] = i;
		if (cnt == s)
			cnt = 0, st[++tot] = i, ed[tot - 1] = i - 1;
		bl[i] = tot, cnt++, sz[tot]++;
	}
	ed[tot] = n;
	for (int i = 1; i <= tot; i++)
		for (int j = st[i]; j <= ed[i]; j++)
			add(i, a[j], 1);
	for (int i = 1; i <= m; i++)
		cin >> q[i];
	for (int i = 1; i <= n; i++) {
		ans += i - 1 - query(tot + 1, a[i]);
		add(tot + 1, a[i], 1);
	}
	for (int i = 1; i <= m; i++) {
		int t = w[q[i]], id = bl[t];
		cout << ans << endl;
		for (int j = t - 1; j >= st[id]; j--)
			if (!d[j] && a[j] > q[i])
				ans--;
		for (int j = t + 1; j <= ed[id]; j++)
			if (!d[j] && a[j] < q[i])
				ans--;
		d[t] = 1;
		for (int j = 1; j < id; j++)
			ans -= sz[j] - query(j, q[i]);
		for (int j = id + 1; j <= tot; j++)
			ans -= query(j, q[i]);
		add(id, q[i], -1);
		sz[id]--;
	}
	return 0;
}