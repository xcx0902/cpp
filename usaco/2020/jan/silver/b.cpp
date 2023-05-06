#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, m, l = 1, r = 1e12;

bool check(int x) {
    int g = 0, kk = k;
    while (kk > 0 && g < n) {
        int y = (n - g) / x;
        if (y < m) return (n - g + m - 1) / m <= kk;
        int t = (n - x * y - g) / y + 1;
        if (t > kk) t = kk;
        g += y * t, kk -= t;
    }
    return g >= n;
}

signed main() {
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    cin >> n >> k >> m;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}