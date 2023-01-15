#include <bits/stdc++.h>
using namespace std;

int t, d, ans, n, f[1050][1050], cnt[15];
string s;

int main() {
    cin >> t;
    while (t--) {
        memset(f, 0, sizeof f);
        memset(cnt, 0, sizeof cnt);
        cin >> s >> d;
        n = s.size();
        for (char c : s) cnt[c - '0']++;
        f[0][0] = 1;
        for (int i = 0; i < (1 << n); i++)
            for (int j = 0; j < d; j++)
                for (int k = 0; k < n; k++)
                    if ((i & (1 << k)) == 0)
                        f[i | (1 << k)][(j * 10 + s[k] - '0') % d] += f[i][j];
        ans = f[(1 << n) - 1][0];
        for (int i = 0; i < 10; i++)
            for (int j = 1; j <= cnt[i]; j++) ans /= j;
        cout << ans << endl;
    }
    return 0;
}