#include <bits/stdc++.h>
using namespace std;

const int M = 55;
int t, n, m, q, tot, a[M][M];
vector<int> g[M];

void init() {
    memset(a, 0, sizeof a);
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < g[i].size(); j++)
            a[g[i][j]][i] = 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i][m + 1];
}

int gauss() {
    int r, c;
    for (r = 1, c = 1; r <= n, c <= m; r++, c++) {
        int id = r;
        for (int i = r + 1; i <= n; i++)
            if (a[id][c] < a[i][c])
                id = i;
        swap(a[r], a[id]);
        if (a[r][c] == 0) { r--; continue; }
        for (int i = 1; i <= n; i++) {
            if (i == r || a[i][c] == 0) continue;
            for (int j = c; j <= m + 1; j++)
                a[i][j] ^= a[r][j];
        }
    }
    for (int i = r; i <= n; i++)
        if (a[i][m + 1])
            return -1;
    return max(0, m - r + 1);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1, k; i <= m; i++) {
            cin >> k;
            g[i].clear();
            for (int j = 1, t; j <= k; j++) {
                cin >> t;
                g[i].push_back(t);
            }
        }
        cin >> q;
        cout << "Case " << ++tot << ":" << endl;
        while (q--) {
            init();
            int f = gauss();
            if (f == -1) cout << 0 << endl;
            else cout << (1LL << f) << endl;
        }
    }
    return 0;
}