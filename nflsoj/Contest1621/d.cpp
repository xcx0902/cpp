#include <bits/stdc++.h>
using namespace std;

int n, ans, lst, x[15], y[15], p[15], turned[15];
// 1 up 2 left 3 down 4 right

// 0 invalid 1 turned 2 not turned
int valid(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        int dir = y1 < y2? 3 : 1;
        if (lst != dir) {
            lst = dir;
            return 1;
        } else return 2;
    }
    if (y1 == y2) {
        int dir = x1 < x2? 4 : 2;
        if (lst != dir) {
            lst = dir;
            return 1;
        } else return 2;
    }
    return 0;
}

bool check() {
    if (!valid(0, 0, x[p[1]], y[p[1]]))
        return false;
    for (int i = 1; i < n; i++) {
        int k = valid(x[p[i]], y[p[i]], x[p[i + 1]], y[p[i + 1]]);
        if (!k) return false;
        else if (k == 1) turned[i] = true;
    }
    int k = valid(x[p[n]], y[p[n]], 0, 0);
    if (!k) return false;
    else if (k == 1) turned[n] = true;
    for (int i = 1; i <= n; i++)
        if (!turned[i])
            return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++)
        p[i] = i;
    do ans += check(); while (next_permutation(p + 1, p + n + 1));
    cout << ans << endl;
    return 0;
}