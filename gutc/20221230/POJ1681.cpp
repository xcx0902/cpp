#include <iostream>
#include <cstring>
using namespace std;

const int d[5][2] = {0, 0, -1, 0, 1, 0, 0, -1, 0, 1};
int t, n, ans, a[250][250];

void reset() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 5; k++) {
                int x = i + d[k][0], y = j + d[k][1];
                if (x >= 0 && y >= 0 && x < n && y < n)
                    a[i * n + j][x * n + y] = 1;
            }
}

bool gauss() {
    int i, j, k;
    for (i = 0, j = 0; i < n * n && j < n * n; i++, j++) {
        k = i;
        for (; k < n * n; k++)
            if (a[k][j]) break;
        for (int t = j; t <= n * n; t++)
            if (i != k) swap(a[i][t], a[k][t]);
        if (!a[i][j]) {
            i--;
            continue;
        }
        for (k = i + 1; k < n * n; k++) {
            if (a[k][j])
                for (int t = j; t <= n * n; t++)
                    a[k][t] ^= a[i][t];
        }
    }
    k = i;
    for (i = k; i < n * n; i++)
        if (a[i][n * n]) return false;
    for (i = k - 1; i >= 0; i--) {
        for (j = i + 1; j < n * n; j++)
            a[i][n * n] ^= (a[i][j] & a[j][n * n]);
    }
    return true;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        memset(a, 0, sizeof a);
        reset();
        for (int i = 0; i < n * n; i++) {
            char c;
            cin >> c;
            a[i][n * n] = (c == 'w');
        }
        if (!gauss()) cout << "inf" << endl;
        else {
            ans = 0;
            for (int i = 0; i < n * n; i++)
                ans += a[i][n * n];
            cout << ans << endl;
        }
    }
    return 0;
}