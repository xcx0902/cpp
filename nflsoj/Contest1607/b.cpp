#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200005;
int n, m, s, op, p, w, a[N], bl[N], l[N], f[N], to[N];

void replace(int p, int w) {
    a[p] = w;
    for (int i = l[bl[p] + 1] - 1; i >= l[bl[p]]; i--)
        if (i + a[i] >= l[bl[i] + 1]) f[i] = 1, to[i] = i + a[i];
        else f[i] = f[i + a[i]] + 1, to[i] = to[i + a[i]];
}

int query(int p) {
    int ans = 0;
    while (p <= n)
        ans += f[p], p = to[p];
    return ans;
}

signed main() {
    cin >> n;
    s = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        bl[i] = (i - 1) / s + 1;
        if (bl[i] != bl[i - 1]) l[bl[i]] = i;
    }
    l[bl[n] + 1] = n + 1;
    for (int i = n; i >= 1; i--)
        if (i + a[i] >= l[bl[i] + 1]) f[i] = 1, to[i] = i + a[i];
        else f[i] = f[i + a[i]] + 1, to[i] = to[i + a[i]];
    cin >> m;
    while (m--) {
        cin >> op >> p;
        if (op == 1) cout << query(p + 1) << endl;
        else cin >> w, replace(p + 1, w);
    }
    return 0;
}