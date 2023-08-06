#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200005, p = 998244353;
int n, f[N], sum[N];
string s;

signed main() {
    cin >> n >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        int x = s[i] - '0';
        f[i] = (f[i - 1] * 10 % p + sum[i - 1] * x % p + x + p) % p;
        sum[i] = (sum[i - 1] + f[i]) % p;
    }
    cout << f[n] % p << endl;
    return 0;
}
