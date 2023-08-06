#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10, K = 20;
int n, m, l = 1, r, ans[N], x[N], y[N];
struct node {
    int x, y;
    bool operator < (const node &a) const {
        if (x != a.x) return x < a.x;
        return y < a.y;
    }
} p[N], A[N];

signed main() {
    cin >> m;
    n = m = m / 2;
    for (int i = 1, k, x, y; i <= n; i++) {
        cin >> k >> x >> y;
        p[i] = (node){x, y};
    }
    for (int i = 1, k, x; i <= m; i++) {
        cin >> k >> x;
        A[i] = (node){x, i};
    }
    sort(p + 1, p + n + 1);
    sort(A + 1, A + m + 1);
    for (int i = 1; i <= n; i++) {
        while (l < r && (p[i].y - y[r]) * (x[r] - x[r - 1]) >=
                        (p[i].x - x[r]) * (y[r] - y[r - 1])) r--;
        x[++r] = p[i].x, y[r] = p[i].y;
    }
    for (int i = 1; i <= m; i++) {
        while (l < r && (y[l + 1] - y[l]) >= -A[i].x * (x[l + 1] - x[l])) l++;
        ans[A[i].y] = A[i].x * x[l] + y[l];
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
    return 0;
}