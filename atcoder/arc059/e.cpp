#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 405, p = 1e9 + 7;
int n, c, a[N], b[N], pw[N][N], f[N][N];

signed main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= 400; i++)
        pw[i][0] = 1;
    for (int i = 1; i <= 400; i++)
        for (int j = 1; j <= 400; j++)
            pw[i][j] = pw[i][j - 1] * i % p;
    for (int i = 1; i <= 400; i++)
        for (int j = 0; j <= 400; j++)
            pw[i][j] = (pw[i][j] + pw[i - 1][j]) % p;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= c; j++)
            for (int k = 0; k <= j; k++)
                f[i][j] = (f[i][j] + f[i - 1][j - k] * (pw[b[i]][k] - pw[a[i] - 1][k] + p) % p) % p;
    cout << f[n][c] << endl;
    return 0;
}
