#include <bits/stdc++.h>
using namespace std;

int n, l, r, mid, ans, a[500001];

bool check(int x) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] >= x)
            cnt++;
    return cnt >= x;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    r = n;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}