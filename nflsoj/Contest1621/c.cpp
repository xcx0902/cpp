#include <bits/stdc++.h>
using namespace std;

int n, ans, a[25], num[25][15], id[25];

bool check() {
    int mxlen = 0;
    for (int i = 1; i <= id[0]; i++)
        mxlen = max(mxlen, num[id[i]][0]);
    for (int i = 1; i <= mxlen; i++) {
        int sum = 0;
        for (int j = 1; j <= id[0]; j++)
            sum += num[id[j]][i];
        if (sum >= 10) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (a[i]) {
            num[i][++num[i][0]] = a[i] % 10;
            a[i] /= 10;
        }
    }
    for (int i = 1; i < (1 << n); i++) {
        memset(id, 0, sizeof id);
        for (int j = 1; j <= n; j++)
            if (i & (1 << (j - 1)))
                id[++id[0]] = j;
        if (check()) {
            // for (int j = 1; j <= id[0]; j++)
            //     cout << id[j] << " ";
            // cout << endl;
            ans = max(ans, id[0]);
        }
    }
    cout << ans << endl;
    return 0;
}