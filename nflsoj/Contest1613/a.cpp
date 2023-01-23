#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, l = 1, r = 1, ans, a[200001];
map<int, int> cnt;

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (r <= n) {
        cnt[a[r]]++;
        while (cnt[a[r]] >= k) {
            ans += n - r + 1;
            cnt[a[l++]]--;
        }
        r++;
    }
    cout << ans << endl;
    return 0;
}