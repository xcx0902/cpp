#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, a, b, ans;

signed main() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        ans = 1e18;
        for (int i = 1; i <= 2 * sqrt(max(a, b)); i++)
            ans = min(ans, i - 1 + (a + i - 1) / i + (b + i - 1) / i);
        cout << ans << endl;
    }
    return 0;
}