#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
int n, m, sz, a[N], f[N], ans[N];
struct node {
    int t, k, id;
    bool operator < (node x) const {
        return k < x.k;
    }
} q[N];

inline void init(int st) {
    for (int i = 0; i < st; i++) f[i] = a[i];
    for (int i = st; i <= n; i++) f[i] = f[i - st] + a[i];
}

int main() {
    cin >> n;
    sz = sqrt(n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    cin >> m;
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &q[i].t, &q[i].k), q[i].id = i;
    sort(q + 1, q + m + 1);
    for (int i = 1; i <= m; i++) {
        int t = q[i].t, k = q[i].k;
        if (q[i].k > sz) {
            while (t <= n)
                ans[q[i].id] += a[t], t += k;
        } else {
            if (k != q[i - 1].k) init(k);
            ans[q[i].id] = f[t + (n - t) / k * k] - ((t >= k) ? f[t - k] : 0);
        }
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}