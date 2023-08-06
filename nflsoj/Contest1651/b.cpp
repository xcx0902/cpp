#include <bits/stdc++.h>
using namespace std;

int n, m, t, ans, lst, a[100005];

int main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = t + 1;
    for (int i = 1; i <= n - m + 1; i++) {
        int st = i, ed = i + m - 1;
        // cerr << "st = " << st << endl;
        // cerr << "ed = " << ed << endl;
        // cerr << "tmp = " << a[ed + 1] - 1 - lst << endl;
        ans = max(ans, a[ed + 1] - 1 - lst);
        lst = a[i];
    }
    if (m >= n) ans = t;
    cout << ans << endl;
    return 0;
}
