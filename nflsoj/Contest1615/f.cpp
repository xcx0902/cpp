#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int t, n, m, ans = 1, a[200005];

int solve(int x, int lim) {
    vector<int> p;
    for (int i = 2; i <= sqrt(x); i++) 
        if (x % i == 0) {
            p.push_back(i);
            while (x % i == 0) x /= i;
        }
    if (x > 1) p.push_back(x);
    int v = p.size(), ret = 0;
    for (int i = 0; i < (1 << v); i++) {
        int mul = 1;
        for (int j = 0; j < v; j++)
            if (i & (1 << j))
                mul *= p[j];
        if (__builtin_popcount(i) & 1) ret -= (lim / mul);
        else ret += (lim / mul);
    }
    return ret;
}

signed main() {
    cin >> t;
    while (t--) {
        // cerr << "t = " << t << endl;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i - 1] % a[i]) { cout << 0 << endl; goto end; }
            (ans *= solve(a[i - 1] / a[i], m / a[i])) %= mod;
        }
        cout << ans << endl;
        end:;
    }
    return 0;
}