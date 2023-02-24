#include <bits/stdc++.h>
using namespace std;

int n, m, ans, a[105], b[105];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= m; i++)
        ans += a[b[i]];
    cout << ans << endl;
    return 0;
}
