#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
struct edge { int u, v, w; } e[N];
int n, m, q, p[N], sz[N], ans[N];
vector<int> g[N];
vector<pair<int&, int>> hsz, hfa;
map<int, vector<int>> mp[N];

int find(int x) {
    while (x != p[x]) x = p[x];
    return p[x];
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        if (sz[x] < sz[y]) swap(x, y);
        hsz.push_back({sz[x], sz[x]}); sz[x] += sz[y];
        hfa.push_back({p[y], p[y]});   p[y] = x;
    }
}

void restore(int h) {
    while (hfa.size() > h) {
        hfa.back().first = hfa.back().second; hfa.pop_back();
        hsz.back().first = hsz.back().second; hsz.pop_back();
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1, u, v, w; i <= m; i++) {
        scanf("%lld%lld%lld", &u, &v, &w);
        e[i] = {u, v, w};
        g[w].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        p[i] = i, sz[i] = 1;
    scanf("%lld", &q);
    for (int i = 1, k, p; i <= q; i++) {
        ans[i] = 1;
        scanf("%lld", &k);
        while (k--) {
            scanf("%lld", &p);
            mp[e[p].w][i].push_back(p);
        }
    }
    for (int w = 1; w <= 5e5; w++) {
        if (g[w].empty()) continue;
        for (auto p : mp[w]) {
            if (!ans[p.first]) continue;
            int h = hfa.size();
            for (int i: p.second) {
                if (find(e[i].u) == find(e[i].v))
                    ans[p.first] = 0;
                merge(e[i].u, e[i].v);
            }
            restore(h);
        }
        for (int i: g[w])
            merge(e[i].u, e[i].v);
    }
    for (int i = 1; i <= q; i++)
        if (ans[i]) puts("YES");
        else puts("NO");
    return 0;
}