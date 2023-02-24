#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n, d, k;
int rptTimes, rptPeriod, rptIn;

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> d >> k;
        d %= n;
        rptTimes = __gcd(n, d);
        rptPeriod = n / rptTimes;
        rptIn = (k + rptPeriod - 1) / rptPeriod;
        k -= (rptIn - 1) * rptPeriod;
        // fprintf(stderr, "rptTimes = %d, rptPeriod = %d, rptIn = %d\n", rptTimes, rptPeriod, rptIn);
        cout << (rptIn - 1 + (k - 1) * d) % n << endl;
    }
    return 0;
}
