#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, d, k, x, sum;

int qpow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int tmp = qpow(a, b / 2);
    if (b % 2) return tmp * tmp * a;
    else       return tmp * tmp;
}

int calc(int k, int d) {
    int ret = 0;
    for (int i = 0; i <= d; i++)
        ret += qpow(k, i);
    return ret;
}

int f(int k, int d, int x) {
    if (calc(k, d) < x) return 1e18;
    x = calc(k, d) - x;
    int ret = 0;
    for (int i = d; i >= 0; i--) {
        ret += x / calc(k, i);
        x %= calc(k, i);
    }
    return ret;
}

int ans(int k, int d, int x) {
    int ret = f(k, d, x);
    for (int i = 0; i <= d - 1; i++)
        ret = min(ret, f(k, i, x) + 1);
    return ret;
}

signed main() {
    cin >> t;
    while (t--) {
        cin >> d >> k >> x;
        sum = calc(k, d);
        cout << ans(k, d, x) << endl;
    }
    return 0;
}
