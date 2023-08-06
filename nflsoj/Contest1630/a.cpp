#include <bits/stdc++.h>
using namespace std;

int k, n, ans, a[15][25];

int main() {
    cin >> k >> n;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) {
                bool ok = 1;
                for (int s = 1; s <= k; s++) {
                    int pi, pj;
                    for (int t = 1; t <= n; t++)
                        if (a[s][t] == i) pi = t;
                        else if (a[s][t] == j) pj = t;
                    if (pi > pj) ok = 0;
                }
                ans += ok;
            }
    cout << ans << endl;
    return 0;
}
