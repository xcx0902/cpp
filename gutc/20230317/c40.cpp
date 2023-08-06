#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, tmp, now, ans, cnt, a[200005];
struct node { int x, y; } t[200005];

bool cmp(node a, node b) {
    if (a.x >= now) return a.y == b.y ? a.x > b.x : a.y > b.y;
    else return a.x == b.x ? a.y > b.y : a.x > b.x;
}

signed main() {
    std::mt19937 mt_rand(std::chrono::system_clock::now().time_since_epoch().count());
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> t[i].x;
    for (int i = 1; i <= m; i++) cin >> t[i].y;
    for (int _ = 1; _ <= 100; _++) {
        tmp = 0;
        sort(t + 1, t + 1 + m, cmp);
        for (int i = n; i >= 1; i--)
            for (int j = 1; j <= a[i]; j++)
                tmp += max(t[++cnt].x - n + i, 1LL) * t[cnt].y;
        now = mt_rand() % n;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}