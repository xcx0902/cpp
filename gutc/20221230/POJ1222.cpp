#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define free _44dec507_d11c_4405_95f0_0f287168
using namespace std;

const int N = 50;
int n, m, free, t, tot, a[N][N], x[N], f[N];

int gauss() {
    int c, r;
    free = 0;
    for (r = 0, c = 0; r < n && c < m; r++, c++) {
        int id = r;
        for (int i = r + 1; i < n; i++)
            if (abs(a[i][c]) > abs(a[id][c]))
                id = i;
        if (a[id][c] == 0) {
            r--; f[++free] = c;
            continue;
        }
        for (int i = 1; i <= m; i++)
            swap(a[r][i], a[id][i]);
        for (int i = r + 1; i < n; i++)
            if (a[i][c] != 0)
                for (int j = c; j <= m; j++)
                    a[i][j] = a[i][j] ^ a[r][j];
    }
    for (int i = r; i < n; i++)
        if (a[r][c])
            return -1;
    if (r < m) return m - r;
    for (int i = m - 1; i >= 0; i--) {
        x[i] = a[i][m];
        for (int j = i + 1; j < m; j++)
            x[i] ^= (a[i][j] && x[j]);
    }
    return 0;
}

int main() {
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof a);
        memset(f, 0, sizeof f);
        memset(x, 0, sizeof x);
        n = m = 30;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                int t = i * 6 + j;
                a[t][t] = 1;
                if (i > 0) a[(i - 1) * 6 + j][t] = 1;
                if (i < 4) a[(i + 1) * 6 + j][t] = 1;
                if (j > 0) a[i * 6 + j - 1][t] = 1;
                if (j < 5) a[i * 6 + j + 1][t] = 1;
            }
        }
        for (int i = 0; i < 30; i++)
            cin >> a[i][30];
        gauss();
        cout << "PUZZLE #" << ++tot << endl;
        for (int i = 0; i < 5; i++, cout << endl)
            for (int j = 0; j < 6; j++)
                cout << x[i * 6 + j] << " ";
    }
    return 0;
}