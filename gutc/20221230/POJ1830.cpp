#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 55;
int t, n, tot, u, v, a[N][N], x[N], st[N], ed[N];

int gauss(int n, int m) {
    memset(x, 0, sizeof x);
    int r, c;
    for (r = 0, c = 0; r < n && c < m; r++, c++) {
        int id = r;
        for (int i = r + 1; i < n; i++)
            if (abs(a[i][c]) > abs(a[id][c]))
                id = i;
        for (int i = r; i <= m; i++)
            swap(a[r][i], a[id][i]);
        if (a[r][c] == 0) { r--; continue; }
        for (int i = r + 1; i < n; i++)
            if (a[i][c])
                for (int j = c; j <= m; j++)
                    a[i][j] ^= a[r][j];
    }
    for (int i = r; i < n; i++)
        if (a[i][c] != 0)
            return -1;
    return 1 << (m - r);
}

int main() {
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof a);
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> st[i];
        for (int i = 0; i < n; i++)
            cin >> ed[i];
        for (int i = 0; i < n; i++)
            a[i][n] = (st[i] ^ ed[i]), a[i][i] = 1;
        while (cin >> u >> v && u + v)
            a[v - 1][u - 1] = 1;
        int ans = gauss(n, n);
        if (ans == -1) cout << "Oh,it's impossible~!!" << endl;
        else cout << ans << endl;
    }
    return 0;
}