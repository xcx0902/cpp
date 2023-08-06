#include <bits/stdc++.h>
#define int long long
using namespace std;

const int p = 1e9 + 7;

int qpow(int a, int b, int p) {
    if (b == 0) return 1 % p;
    if (b == 1) return a % p;
    int tmp = qpow(a, b / 2, p) % p;
    if (b % 2)
        return tmp * tmp % p * a % p;
    else
        return tmp * tmp % p;
}

int fac[2000005], inv[2000005];

void getFactorial() {
    fac[0] = 1;
    for (int i = 1; i <= 2e6 + 1; i++)
        fac[i] = fac[i - 1] * i % p;
    inv[2000001] = qpow(fac[2000001], p - 2, p);
    for (int i = 2e6; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % p;
}

int C(unsigned N, unsigned M) {
    return fac[N] * inv[M] % p * inv[N - M] % p;
}

int r1, c1, r2, c2, ans;

signed main() {
    cin >> r1 >> c1 >> r2 >> c2;
    getFactorial();
    for (int i = r1; i <= r2; i++)
        ans = (ans + C(i + c2 + 1, i + 1) - C(i + c1, i + 1) + p) % p;
    cout << ans << endl;
    return 0;
}
