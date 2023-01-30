#include <bits/stdc++.h>
#define mn (mnn == 0x3f3f3f3f3f3f3f3fLL? 0 : mnn)
#define int long long
using namespace std;

const int N = 1000005;
int n, A, B, l = 1, r = 1, mx, mnn = 0x3f3f3f3f3f3f3f3fLL, ans, x, y, a[N];
set<int> s;

void ins(int x) {
    s.insert(x);
    mx = *s.rbegin();
    mnn = *s.begin();
}

void del(int x) {
    s.erase(x);
    mx = *s.rbegin();
    mnn = *s.begin();
}

signed main() {
    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (r <= n) {
        if (l == x && r == y) break;
        x = l, y = r;
        // cerr << l << " " << r << endl;
        // cerr << "mx = " << mx << endl;
        // cerr << "mn = " << mn << endl;
        ins(a[r]);
        while (mx - mn < A && r < n)
            ins(a[++r]);
        while (mx - mn <= B && r < n) {
            ans = max(ans, r - l + 1);
            ins(a[++r]);
            if (mx - mn <= B) ans = max(ans, r - l + 1);
        }
        while (mx - mn > B && l <= r)
            del(a[l++]);
    }
    cout << ans << endl;
    return 0;
}