#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005;
int n, m, p = 1, ans;
multiset<int> s;
pair<int, int> a[N], b[N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second >> a[i].first;
    for (int i = 1; i <= m; i++)
        cin >> b[i].second >> b[i].first;
    sort(a + 1, a + n + 1, greater<pair<int, int>>());
    sort(b + 1, b + m + 1, greater<pair<int, int>>());
    for (int i = 1; i <= n; i++) {
        while (p <= m && b[p].first >= a[i].first)
            s.insert(b[p++].second);
        auto it = s.lower_bound(a[i].second);
        if (it == s.end()) {
            cout << -1 << endl;
            return 0;
        }
        ans += *it;
        s.erase(it);
    }
    cout << ans << endl;
    return 0;
}