#include <bits/stdc++.h>
using namespace std;

const int N = 301;
int n, pos = 1, c[N], ans[N], a[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            cin >> a[i][j];
    for (int i = 2; i <= n; i++) {
        if (ans[i - 1] >= ans[pos]) {
            if (ans[i - 1] + a[i - 1][i] - ans[pos] == a[pos][i])
                ans[i] = ans[i - 1] + a[i - 1][i];
            else ans[i] = ans[pos = i - 1] - a[i - 1][i];
        } else {
            if (ans[pos] - (ans[i - 1] - a[i - 1][i]) == a[pos][i])
                ans[i] = ans[i - 1] - a[i - 1][i];
            else ans[i] = ans[pos = i - 1] + a[i - 1][i];
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}