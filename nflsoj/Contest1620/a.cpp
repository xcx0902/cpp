#include <bits/stdc++.h>
using namespace std;

int n, p, k, l, r, mid, ans = -1, f[1001];
struct node { int v, w, x; };
vector<node> g[1001];

void spfa() {
    memset(f, 0x7f, sizeof f);
    queue<int> q;
    f[1] = 0;
    q.push(1);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (node v: g[u])
            if (f[u] + v.x < f[v.v]) {
                f[v.v] = f[u] + v.x;
                q.push(v.v);
            }
    }
}

bool check(int m) {
    for (int i = 1; i <= n; i++)
        for (node &j: g[i])
            if (j.w <= m) j.x = 0;
            else j.x = 1;
    spfa();
    return f[n] <= k;
}

int main() {
    cin >> n >> p >> k;
    for (int i = 1, u, v, w; i <= p; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        r = max(r, w);
    }
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}