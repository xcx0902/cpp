#include <bits/stdc++.h>
using namespace std;

int n, m, l[35], r[35], f[35][245], ans[35];

void dfs(int x, int y) {
    for (int i = l[x]; i <= r[x]; i++)
        if (f[x - 1][y - i]) {
            ans[x] = i;
            dfs(x - 1, y - i);
            return;
        }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = l[i]; k <= r[i]; k++)
                f[i][j] |= f[i - 1][j - k];
    if (!f[n][m]) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        dfs(n, m);
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
