#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 300005;
int n, m, k, l, r, a, c[N], p[N], now[N], ans[N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    cin >> k;
    for (int t = 1; t <= k; t++) {
        cin >> l >> r >> a;
        if (l <= r) {
            for (int i = l; i <= r; i++)
                now[c[i]] += a;
        } else {
            for (int i = l; i <= m; i++)
                now[c[i]] += a;
            for (int i = 1; i <= r; i++)
                now[c[i]] += a;
        }
        for (int i = 1; i <= n; i++)
            if (now[i] >= p[i])
                ans[i] = t, now[i] = -114514191911451419;
    }
    for (int i = 1; i <= n; i++)
        if (ans[i]) cout << ans[i] << endl;
        else cout << "NIE" << endl;
    return 0;
}
