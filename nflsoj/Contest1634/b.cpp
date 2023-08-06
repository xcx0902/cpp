#include <bits/stdc++.h>
using namespace std;

int n, m, k;
double ans, a[10001][101], mx[10001];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            int p; double s;
            cin >> p >> s;
            a[p][i] = s;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mx[i] = max(mx[i], a[i][j]);
    sort(mx + 1, mx + n + 1, greater<double>());
    for (int i = 1; i <= k; i++)
        ans += mx[i];
    printf("%.1lf\n", ans);
    // cout << fixed << setprecision(1) << ans << endl;
    return 0;
}
