#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, m, a[N], f[15][N];

int main() {
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--) {
            int k = -1;
            while (++k, k * k <= j)
                f[i][j] = min(f[i][j], f[i - 1][j - k * k] + (a[i] - k) * (a[i] - k));
        }
    cout << (f[n][m] > 1e9 ? -1 : f[n][m]);
    return 0;
}