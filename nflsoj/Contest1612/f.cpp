#include <bits/stdc++.h>
using namespace std;

int n, m, g[20][20], a[1 << 20], f[1 << 20];

int main() {
    memset(f, 0x3f, sizeof f);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u - 1][v - 1] = g[v - 1][u - 1] = 1;
    }
    a[0] = 1;
    for (int S = 1; S < (1 << n); S++) {
        int x = __builtin_ctz(S);
        a[S] = a[S ^ (1 << x)];
        for (int i = 0; i < n; i++)
            if (S & (1 << i))
                a[S] &= (x == i || g[x][i]);
    }
    f[0] = 0;
    for (int S = 1; S < (1 << n); S++)
        for (int T = S; T; T = (T - 1) & S)
            if (a[T])
                f[S] = min(f[S], f[S ^ T] + 1);
    cout << f[(1 << n) - 1] << endl;
    return 0;
}