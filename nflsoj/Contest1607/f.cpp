#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 400005, mod = 1e9 + 7;
// sum:区间和 mul:区间平方和 add:lazytag
int n, m, mul[N], sum[N], add[N];

void pushup(int p) {
	sum[p] = (sum[p << 1] + sum[p << 1 | 1]) % mod;
	mul[p] = (mul[p << 1] + mul[p << 1 | 1]) % mod;
}

void pushdown(int l, int r, int p) {
	int mid = (l + r) >> 1;
	if (add[p]) {
		// (ai+x)^2 = ai^2 + 2aix + x^2，相较于 Σai^2 多 Σ2aix + Σx^2 = Σai * 2x + len * x^2
		mul[p << 1    ] += (mid - l + 1) * add[p] * add[p] + 2 * add[p] * sum[p << 1    ];
		mul[p << 1 | 1] += (r - mid)     * add[p] * add[p] + 2 * add[p] * sum[p << 1 | 1];
		add[p << 1    ] += add[p];
		add[p << 1 | 1] += add[p];
		sum[p << 1    ] += add[p] * (mid - l + 1);
		sum[p << 1 | 1] += add[p] * (r - mid);
		add[p] = 0;
		mul[p << 1] %= mod; mul[p << 1 | 1] %= mod;
		add[p << 1] %= mod; add[p << 1 | 1] %= mod;
		sum[p << 1] %= mod; sum[p << 1 | 1] %= mod;		
	}
}

void build(int l, int r, int p = 1) {
	if (l == r) {
		cin >> sum[p];
		mul[p] = sum[p] * sum[p] % mod;
		return;
	}
	int mid = (l + r) >> 1;
	build(l      , mid, p << 1    );
	build(mid + 1, r  , p << 1 | 1);
	pushup(p);
}

void update(int x, int L, int R, int l = 1, int r = n, int p = 1) {
	if (L <= l && R >= r) {
		mul[p] += (r - l + 1) * x * x + 2 * sum[p] * x;
		add[p] += x, sum[p] += (r - l + 1) * x;
		mul[p] %= mod, add[p] %= mod, sum[p] %= mod;
		return;
	}
	pushdown(l, r, p);
	int mid = (l + r) >> 1;
	if (L <= mid) update(x, L, R, l      , mid, p << 1    );
	if (R >  mid) update(x, L, R, mid + 1, r  , p << 1 | 1);
	pushup(p);
}

int query(int L, int R, int l = 1, int r = n, int p = 1) {
	if (L <= l && R >= r)
		return mul[p] % mod;
	pushdown(l, r, p);
	int mid = (l + r) >> 1, ans = 0;
	if (L <= mid) ans += query(L, R, l      , mid, p << 1    );
	if (R >  mid) ans += query(L, R, mid + 1, r  , p << 1 | 1);
	return ans % mod;
}

signed main() {
	cin >> n >> m;
	build(1, n);
	while (m--) {
		char op;
		int l, r, k;
		cin >> op;
		if (op == 'Q') {
			cin >> l >> r;
			cout << query(l, r) % mod << endl;
		} else {
			cin >> l >> r >> k;
			update(k, l, r);
		}
	}
	return 0;
}