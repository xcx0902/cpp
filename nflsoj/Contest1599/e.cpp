#include <bits/stdc++.h>
using namespace std;

int n, l, sa, sc, a[101], c[101], f[2][2][101][501];
double ans = 1e16;

int main() {
    cin >> n >> l;
    l = min(l, n - l);
    for (int i = 1; i <= n; i++) cin >> a[i], sa += a[i];
    for (int i = 1; i <= n; i++) cin >> c[i], sc += c[i];
    memset(f[0], 0x3f, sizeof f[0]);
    memset(f[1], -0x3f, sizeof f[1]);
    f[0][0][0][0] = f[1][0][0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= min(l, i); j++)
            for (int k = 0; k <= sa; k++) {
                int &x = f[0][i & 1][j][k], &y = f[1][i & 1][j][k];
                x = f[0][i & 1 ^ 1][j][k];
                y = f[1][i & 1 ^ 1][j][k];
                if (k >= a[i] && j >= 1) {
                    x = min(x, f[0][i & 1 ^ 1][j - 1][k - a[i]] + c[i]);
                    y = max(y, f[1][i & 1 ^ 1][j - 1][k - a[i]] + c[i]);
                }
            }
    for (int i = 1; i <= sa; i++) {
        int x = f[0][n & 1][l][i], y = f[1][n & 1][l][i];
        if (x <= 1e9) ans = min(ans, 1LL * x * (sc - x) * 1.0 / (1LL * i * (sa - i)));
        if (y > -1e9) ans = min(ans, 1LL * y * (sc - y) * 1.0 / (1LL * i * (sa - i)));
    }
    printf("%.3lf", ans);
    return 0;
}