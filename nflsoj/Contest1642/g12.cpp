#include <bits/stdc++.h>
using namespace std;

int n, ans, f[50005];
pair<int, int> a[50005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second, f[i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[j].first >= a[i].first && a[j].second >= a[i].second)
                f[i] = max(f[i], f[j] + 1);
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        cout << 0 << " ";
    cout << endl;
    return 0;
}