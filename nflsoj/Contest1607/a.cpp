#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500005, M = 805;
int n, m, s, a[N], bl[N], v[M], mx[M], mn[M]; 

int query(int l, int r) {
	int x = bl[l], y = bl[r], ans = 0, m = 0x3f3f3f3f3f3f3f3fLL;
	if (x == y)
		for (int i = l; i <= r; i++) {
			ans = max(ans, a[i] - m);
			m = min(m, a[i]);
		}
	else {
		for (int i = l; i <= min(x * s, r); i++) {
			ans = max(ans, a[i] - m);
			m = min(m, a[i]);
		}
		for (int i = x + 1; i <= y - 1; i++) {
			ans = max(ans, max(v[i], mx[i] - m));
			m = min(m, mn[i]);
		}
		for (int i = (y - 1) * s + 1; i <= r; i++) {
			ans = max(ans, a[i] - m);
			m = min(m, a[i]);
		}
	}
	return ans;
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	s = sqrt(n);
	memset(mn, 0x3f, sizeof mn);
	for (int i = 1; i <= n; i++)
		bl[i] = (i - 1) / s + 1;
	for (int i = 1; i <= n; i++) {
		v[bl[i]] = max(v[bl[i]], a[i] - mn[bl[i]]);
		mx[bl[i]] = max(mx[bl[i]], a[i]);
		mn[bl[i]] = min(mn[bl[i]], a[i]);
	}
	for (int i = 1, l, r; i <= m; i++) {
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", query(l, r));
	}
	return 0;
}