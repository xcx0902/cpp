#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, m, k, ans, a[18], c[18][18], f[1 << 18][18];

signed main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1, x, y, z; i <= k; i++) {
        cin >> x >> y >> z;
        c[x - 1][y - 1] = z;
    }
    for (int i = 0; i < n; i++) f[1 << i][i] = a[i];
    for (int S = 0; S < (1 << n); S++)
        for (int i = 0; i < n; i++)
            if (S & (1 << i))
                for (int j = 0; j < n; j++)
                    if (!(S & (1 << j)))
                        f[S | (1 << j)][j] = max(f[S | (1 << j)][j], f[S][i] + c[i][j] + a[j]);
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j)))
                continue;
            if (__builtin_popcount(i) == m)
                ans = max(ans, f[i][j]);
        }
    cout << ans << endl;
    return 0;
}