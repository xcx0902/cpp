#include <bits/stdc++.h>
using namespace std;

int n, x, ans;

int main() {
    cin >> n >> x;
    for (int i = 1, p1, p2, p3; i <= n; i++) {
        cin >> p1 >> p2;
        if (abs(p1 - p2) <= x) ans += max(p1, p2);
        else cin >> p3, ans += p3;
    }
    cout << ans << endl;
    return 0;
}