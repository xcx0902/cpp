#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005, M = 505;
int n, m, blo, id, ans, a[N], bl[N], val[N], cnt[N], f[M][M];
map<int, int> mp;
vector<int> v[N];

void init(int x) {
	memset(cnt, 0, sizeof cnt);
	int mx = 0, ans = 0;
	for (int i = (x - 1) * blo + 1; i <= n; i++) {
		cnt[a[i]]++;
		int t = bl[i];
		if (cnt[a[i]] > mx || (cnt[a[i]] == mx && val[a[i]] < val[ans]))
			ans = a[i], mx = cnt[a[i]];
		f[x][t] = ans;
	}
}

int query(int l, int r, int x) {
	return upper_bound(v[x].begin(), v[x].end(), r) -
	       lower_bound(v[x].begin(), v[x].end(), l);
}

int query(int l, int r) {
	int ret, mx;
	ret = f[bl[l] + 1][bl[r] - 1];
	mx = query(l, r, ret);
	for (int i = l; i <= min(bl[l] * blo, r); i++) {
		int t = query(l, r, a[i]);
		if (t > mx || (t == mx && val[a[i]] < val[ret]))
			ret = a[i], mx = t;
	}
	if (bl[l] != bl[r])
		for (int i = (bl[r] - 1) * blo + 1; i <= r; i++) {
			int t = query(l, r, a[i]);
			if (t > mx || (t == mx && val[a[i]] < val[ret]))
				ret = a[i], mx = t;
		}
	return ret;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	blo = 200;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (!mp[a[i]])
			val[mp[a[i]] = ++id] = a[i];
		a[i] = mp[a[i]];
		v[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		bl[i] = (i - 1) / blo + 1;
	for (int i = 1; i <= bl[n]; i++)
		init(i);
	for (int i = 1, l, r; i <= m; i++) {
		cin >> l >> r;
		l = (l + ans - 1) % n + 1;
		r = (r + ans - 1) % n + 1; 
		if (l > r) swap(l, r);
		ans = val[query(l, r)];
		cout << ans << endl;
	}
	return 0;
}