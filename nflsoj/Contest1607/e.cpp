#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500001, INF = 0x3f3f3f3f;

int n, m, a[N];
struct SegTree {
	int l, r, s, lx, rx, ans;
} t[N << 2];

void build(int l, int r, int p = 1) {
	t[p].l = l; t[p].r = r;
	if (l == r) {
		t[p].s = t[p].lx = t[p].rx = t[p].ans = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l      , mid, p << 1    );
	build(mid + 1, r  , p << 1 | 1);
	t[p].s   = t[p << 1].s + t[p << 1 | 1].s;
	t[p].lx  = max(t[p << 1    ].lx, t[p << 1].s  + t[p << 1 | 1].lx);
	t[p].rx  = max(t[p << 1 | 1].rx, t[p << 1].rx + t[p << 1 | 1].s );
	t[p].ans = max(max(t[p << 1].ans, t[p << 1 | 1].ans), t[p << 1].rx + t[p << 1 | 1].lx);
}

void change(int x, int y, int p = 1) {
	if (t[p].l == t[p].r) {
		t[p].s = t[p].lx = t[p].rx = t[p].ans = y;
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if (x <= mid) change(x, y, p << 1);
	else          change(x, y, p << 1 | 1);
	t[p].s   = t[p << 1].s + t[p << 1 | 1].s;
	t[p].lx  = max(t[p << 1    ].lx, t[p << 1].s  + t[p << 1 | 1].lx);
	t[p].rx  = max(t[p << 1 | 1].rx, t[p << 1].rx + t[p << 1 | 1].s );
	t[p].ans = max(max(t[p << 1].ans, t[p << 1 | 1].ans), t[p << 1].rx + t[p << 1 | 1].lx);
}

SegTree ask(int l, int r, int p = 1) {
	if (l <= t[p].l and r >= t[p].r) return t[p];
	SegTree a, b, ans;
	a.s = a.lx = a.rx = a.ans = -INF;
	b.s = b.lx = b.rx = b.ans = -INF;
	ans.s = 0;
	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid) {
		a = ask(l, r, p << 1);
		ans.s += a.s;
	}
	if (r > mid) {
		b = ask(l, r, p << 1 | 1);
		ans.s += b.s;
	}
	ans.ans = max(max(a.ans, b.ans), a.rx + b.lx);
	ans.lx  = max(a.lx, a.s + b.lx);
	ans.rx  = max(b.rx, b.s + a.rx);
	if (l > mid)  ans.lx = max(ans.lx, b.lx);
	if (r <= mid) ans.rx = max(ans.rx, a.rx);
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, n);
    cin >> m;
	while (m--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			if (x > y) swap(x, y);
			cout << ask(x, y).ans << endl;
		}
		else change(x, y);
	}
	return 0;
}