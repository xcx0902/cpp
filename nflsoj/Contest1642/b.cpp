#include <bits/stdc++.h>
using namespace std;

int calc(int n, int x) {
    int ret = 0;
    while (n) {
        ret += n % x;
        n /= x;
    }
    return ret;
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 2; i <= n - 1; i++)
        ans += calc(n, i);
    // cerr << ans << "/" << n - 2 << endl;
    cout << ans / __gcd(ans, n - 2) << "/" << (n - 2) / __gcd(ans, n - 2) << endl;
    return 0;
}
