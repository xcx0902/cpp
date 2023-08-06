#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int p = 1e9 + 7;

string s;
int k, ans;

int qpow(int a, int b, int p) {
    if (b == 0) return 1 % p;
    if (b == 1) return a % p;
    int tmp = qpow(a, b / 2, p) % p;
    if (b % 2) return tmp * tmp % p * a % p;
    else       return tmp * tmp % p;
}

int sum(int x, int k) {
    if (k == 0) return 1;
    if (k % 2 == 0) return (1 + x % p * sum(x, k - 1)) % p;
    else return sum(x, k / 2) * (1 + qpow(x, k / 2 + 1, p)) % p;
}

signed main() {
    cin >> s >> k;
    int x = sum(qpow(2, s.size(), p), k - 1);
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '0' || s[i] == '5')
            ans = (ans + qpow(2, i, p) * x % p) % p;
    cout << ans << endl;
    return 0;
}
