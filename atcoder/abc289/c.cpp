#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
set<int> tmp, dest, s[15];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dest.insert(i);
    for (int i = 1, c; i <= m; i++) {
        cin >> c;
        for (int j = 1, k; j <= c; j++)
            cin >> k, s[i].insert(k);
    }
    for (int i = 1; i < (1 << m); i++) {
        tmp.clear();
        for (int j = 1; j <= m; j++)
            if (i & (1 << (j - 1))) {
                // cerr << "Chosen " << j << endl;
                for (int k: s[j])
                    tmp.insert(k);
            }
        bool ok = 1;
        for (int j = 1; j <= n; j++)
            if (!tmp.count(j))
                ok = 0;
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}