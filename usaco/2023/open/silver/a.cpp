#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 150005;
int n, q, x, y, id, newid, ans, a[N], s[N], mp[N], first[N], last[N];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mp[i] = a[i];
    cin >> q;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        ans += i * a[i], s[i] = s[i - 1] + a[i];
    // cerr << "original: " << ans << endl;
    // for (int i = 1; i <= n; i++)
    //     if (a[i] != a[i - 1]) first[i] = i;
    //     else first[i] = first[i - 1];
    // for (int i = n; i >= 1; i--)
    //     if (a[i] != a[i + 1]) last[i] = i;
    //     else last[i] = last[i + 1];
    while (q--) {
        cin >> x >> y;
        x = mp[x];
        id = lower_bound(a + 1, a + n + 1, x) - a;
        if (y >= x) {
            newid = lower_bound(a + 1, a + n + 1, y - 1) - a;
            // cerr << "id, newid, 1 = " << id << ", " << newid << endl;
            cout << ans - (s[newid] - s[id]) - id * a[id] + newid * y << endl;
        } else {
            newid = lower_bound(a + 1, a + n + 1, y + 1) - a;
            // cerr << "id, newid, 2 = " << id << ", " << newid << endl;
            cout << ans + (s[id - 1] - s[newid - 1]) - id * a[id] + newid * y << endl;
        }
    }
    return 0;
}
