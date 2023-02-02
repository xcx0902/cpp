#include <bits/stdc++.h>
using namespace std;

int n, m, ans[10];
char a[15][15];

int c2(int x, int y) {
    if (a[x][y] == a[x][y + 1] && a[x][y] == a[x][y + 2] && a[x][y] == a[x][y + 3])
        return 1;
    if (a[x][y] == a[x + 1][y] && a[x][y] == a[x + 2][y] && a[x][y] == a[x + 3][y])
        return 1;
    return 0;
}

int c1(int x, int y) {
    if (a[x][y] == a[x][y + 1] && a[x][y] == a[x + 1][y] && a[x][y] == a[x + 1][y + 1])
        return 1;
    return 0;
}

int c3(int x, int y) {
    if (a[x][y] == a[x][y + 1] && a[x][y] == a[x - 1][y + 1] && a[x][y] == a[x - 1][y + 2])
        return 1;
    if (a[x][y] == a[x + 1][y] && a[x][y] == a[x + 1][y + 1] && a[x][y] == a[x + 2][y + 1])
        return 1;
    return 0;
}

int c4(int x, int y) {
    if (a[x][y] == a[x][y + 1] && a[x][y] == a[x + 1][y + 1] && a[x][y] == a[x + 1][y + 2])
        return 1;
    if (a[x][y] == a[x + 1][y] && a[x][y] == a[x + 1][y - 1] && a[x][y] == a[x + 2][y - 1])
        return 1;
    return 0;
}

int c5(int x, int y) {
    if (a[x][y] == a[x - 1][y] && a[x][y] == a[x - 1][y + 1] && a[x][y] == a[x - 1][y - 1])
        return 1;
    if (a[x][y] == a[x + 1][y] && a[x][y] == a[x + 1][y + 1] && a[x][y] == a[x + 1][y - 1])
        return 1;
    if (a[x][y] == a[x][y - 1] && a[x][y] == a[x + 1][y - 1] && a[x][y] == a[x - 1][y - 1])
        return 1;
    if (a[x][y] == a[x][y + 1] && a[x][y] == a[x + 1][y + 1] && a[x][y] == a[x - 1][y + 1])
        return 1;
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.') continue;
            ans[1] += c1(i, j);
            ans[2] += c2(i, j);
            ans[3] += c3(i, j);
            ans[4] += c4(i, j);
            ans[5] += c5(i, j);
        }
    for (int i = 1; i <= 5; i++)
        cout << ans[i] << endl;
    return 0;
}