#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 105;
int n, k, q, a[N][N], b[N][N];

inline int mod(int x, int y) {
    if (x % y == 0) return y;
    return x % y;
}

signed main() {
    memset(a, 0x1f, sizeof a);
    memset(b, 0x1f, sizeof b);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        a[i][i] = 0;
        for (int j = 1, x; j <= n; j++) {
            cin >> x;
            if (x) a[i][j] = min(a[i][j], 1LL), b[i][j] = 1;
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]), b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if ((x - 1) / n == (y - 1) / n) {
            int ans = a[mod(x, n)][mod(y, n)];
            if (ans < 1e9) cout << ans << endl;
            else cout << -1 << endl;
        } else {
            int ans = 1e9;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    ans = min(ans, a[mod(x, n)][i] + b[i][j] + a[j][mod(y, n)]);
            if (ans < 1e9) cout << ans << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}
