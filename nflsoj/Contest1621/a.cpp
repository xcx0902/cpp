#include <bits/stdc++.h>
using namespace std;

int n, m, q, a[1001][1001], b[1001];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    cin >> q;
    while (q--) {
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            bool ok = 1;
            for (int j = 1; j <= m; j++)
                if (a[i][j] != b[j] && b[j] != -1)
                    ok = 0;
            ans += ok;
        }
        cout << ans << endl;
    }
    return 0;
}