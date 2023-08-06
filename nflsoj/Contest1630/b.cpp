#include <bits/stdc++.h>
using namespace std;

int n, ans, a[1005];
bool vis[1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, 1005U);
        int now = i, ok = 1;
        while (1) {
            if (vis[now]) { ok = 0; break; }
            vis[now] = 1;
            now = a[now];
            if (now == 0) break;
        }
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}
