#include <bits/stdc++.h>
using namespace std;

int t, n, ans, a[101];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            a[i] %= 2;
        ans = 0;
        for (int i = 1; i < n; i++)
            ans += a[i] != a[i + 1];
        cout << n - ans - 1 << endl;
    }
    return 0;
}