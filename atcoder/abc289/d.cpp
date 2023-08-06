#include <bits/stdc++.h>
using namespace std;

int n, m, x, a[15], b[100005], f[100005];
bool has[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i], has[b[i]] = 1;
    cin >> x;
    f[0] = 1;
    for (int i = 1; i <= x; i++) {
        if (has[i]) continue;
        for (int j = 1; j <= n; j++)
            if (i - a[j] >= 0)
                f[i] |= f[i - a[j]];
    }
    if (f[x]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}