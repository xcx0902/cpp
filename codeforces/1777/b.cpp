#include <bits/stdc++.h>
#define int long long
using namespace std;

const int p = 1e9 + 7;
int t, n, f[100001];

void init() {
    f[0] = 1;
    for (int i = 1; i <= 100000; i++)
        f[i] = f[i - 1] * i % p;
}

signed main() {
    init();
    cin >> t;
    while (t--) {
        cin >> n;
        cout << n * (n - 1) % p * f[n] % p << endl;
    }
    return 0;
}