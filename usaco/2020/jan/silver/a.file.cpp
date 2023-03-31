#include <algorithm>
#include <iostream>
using namespace std;

int n, k, mx, ans, full, mod, cur, a[100005];

bool cmp(int a, int b) {
    return (a % mod) > (b % mod);
}

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for (int tmp = 1; tmp <= mx; tmp++) {
        full = 0;
        for (int i = 1; i <= n; i++)
            full += a[i] / tmp;
        if (full < k / 2) break;
        if (full >= k) {
            ans = max(ans, tmp * (k / 2));
            continue;
        }
        mod = tmp;
        sort(a + 1, a + n + 1, cmp);
        cur = tmp * (full - k / 2);
        for (int i = 1; i <= n && i + full <= k; i++)
            cur += a[i] % tmp;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}