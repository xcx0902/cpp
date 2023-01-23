#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, l = 1, r = 1, sum, ans, a[100001];

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (r <= n) {
        while (sum < k && r <= n) sum += a[r++]; r--;
        if (sum >= k) ans += n - r + 1;
        sum -= a[r++, l++];
        // cerr << "(l, r) = " << l << " " << r << endl;
        // cerr << "sum = " << sum << endl;
        // cerr << "ans = " << ans << endl;
    }
    while (sum >= k && l <= n)
        ans++, sum -= a[l++];
    cout << ans << endl;
    return 0;
}