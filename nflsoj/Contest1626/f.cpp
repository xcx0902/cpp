#include <bits/stdc++.h>
using namespace std;

int n, m, a[55][55], s[55][55], f[55][55][55][55];

inline int csum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

int dp(int x1, int y1, int x2, int y2) {
    if (f[x1][y1][x2][y2]) return f[x1][y1][x2][y2];
    if (x1 == x2 && y1 == y2) return 0;
    int ret = 0x3f3f3f3f;
    /*
          y1  y2  
           1 2 3
         -------  
    x1 1 | 2 7 5
           -----
    x2 2 | 1 9 5
    */
    // cut from top to bottom
    for (int i = y1; i < y2; i++)
        ret = min(ret, dp(x1, y1, x2, i) + dp(x1, i + 1, x2, y2));
    // cur from left to right
    for (int i = x1; i < x2; i++)
        ret = min(ret, dp(x1, y1, i, y2) + dp(i + 1, y1, x2, y2));
    // return answer
    return f[x1][y1][x2][y2] = ret + csum(x1, y1, x2, y2);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
    cout << dp(1, 1, n, m) << endl;
    return 0;
}
