#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, diffcnt, ans, sum, lmid, rmid, a[200005], cnt[200005];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    lmid = (1 + n) >> 1;
    if (n % 2) rmid = lmid;
    else rmid = lmid + 1;
    // cerr << lmid << " " << rmid << endl;
    // step 1
    // cerr << "Step 1" << endl;
    for (int i = 1; i <= n; i++)
        cnt[a[i]]++, sum++;
    for (int i = 1; i <= lmid; i++) {
        cnt[a[i]]--, sum--;
        ans += i * (sum - cnt[a[i]]);
        // cerr << "i = " << i << endl;
        // cerr << "sum - cnt[a[i]] = " << sum - cnt[a[i]] << endl;
        cnt[a[n - i + 1]]--, sum--;
    }
    // step 2
    // cerr << "Step 2" << endl;
    sum = 0;
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++)
        cnt[a[i]]++, sum++;
    // // cerr << "sum = " << sum << endl;
    for (int i = n; i >= rmid; i--) {
        cnt[a[i]]--, sum--;
        cnt[a[n - i + 1]]--, sum--;
        ans += (n - i + 1) * (sum - cnt[a[i]]);
        // cerr << "i = " << i << endl;
        // cerr << "sum - cnt[a[i]] = " << sum - cnt[a[i]] << endl;
    }
    // output
    cout << ans << endl;
    return 0;
}
