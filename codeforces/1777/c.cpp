#include <bits/stdc++.h>
#define int long long
#define count _Count
using namespace std;

const int inf = 0x3f3f3f3f3f3f3f3fLL;
const int N = 1e5 + 1;
vector<int> f[N];
int n, m, l, r, count, ans, a[N], cnt[N];

void init() {
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            f[j].push_back(i);
}

void ins(int x) {
    for (int num: f[a[x]]) {
        if (num > m) break;
        if (cnt[num] == 0) count++;
        cnt[num]++;
    }
}

void del(int x) {
    for (int num: f[a[x]]) {
        if (num > m) break;
        cnt[num]--;
        if (cnt[num] == 0) count--;
    }
}

void solve() {
    memset(cnt, 0, sizeof cnt);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    l = 1, r = 1, count = 0, ans = inf;
    while (r <= n) {
        // cerr << "(l, r) = " << l << " " << r << endl;
        // cerr << "count = " << count << endl;
        ins(r);
        // cerr << "After insert " << a[r] << ", count = " << count << endl;
        while (count == m && l <= r) {
            ans = min(ans, a[r] - a[l]);
            del(l++);
        }
        r++;
    }
    cout << (ans == inf? -1 : ans) << endl;
}

signed main() {
    int t;
    init();
    cin >> t;
    while (t--)
        solve();
    return 0;
}