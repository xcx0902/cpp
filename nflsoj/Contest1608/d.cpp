#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, a, b, h[100005];
int l = 1, r = 2e9, mid, ans;

bool check(int x) {
    //	cerr << "checking " << x << endl;
    int need = 0;
    for (int i = 1; i <= n; i++) {
        int hel = h[i] - x * b, dam = a;
        //		cerr << i << "th mob, hel = " << hel << endl;
        if (hel < 0)
            continue;
        if (hel % dam)
            need += hel / dam + 1;
        else
            need += hel / dam;
    }
    return need <= x;
}

signed main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) cin >> h[i];
    a -= b;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}