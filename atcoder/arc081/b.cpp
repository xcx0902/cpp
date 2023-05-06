#include <bits/stdc++.h>
#define int long long
using namespace std;

const int p = 1e9 + 7;
int n, st, ans = 1;
string a, b;

signed main() {
    cin >> n >> a >> b;
    if (a[0] == b[0]) ans = 3, st = 1;
    if (a[0] != b[0]) ans = 6, st = 2;
    for (int i = st; i < n; ) {
        if (a[i] == b[i] && a[i - 1] == b[i - 1]) ans *= 2;
        if (a[i] == b[i] && a[i - 1] != b[i - 1]) ans *= 1;
        if (a[i] != b[i] && a[i - 1] == b[i - 1]) ans *= 2;
        if (a[i] != b[i] && a[i - 1] != b[i - 1]) ans *= 3;
        if (a[i] != b[i]) i += 2;
        else i++;
        ans %= p;
    }
    cout << ans << endl;
    return 0;
}
