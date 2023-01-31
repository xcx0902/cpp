#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n, p[N], sz[N];
vector<pair<int, int>> g[N];
vector<pair<int&, int>> hsz, hfa;

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

int solve(int l, int r) {
    if (l == r) {
        int res = 0;
        for (pair<int, int> p : g[l])
            res += sz[find(p.first)] * sz[find(p.second)];
        return res;
    }
    int res = 0, mid = (l + r) / 2, h = hfa.size();
    for (int i = mid + 1; i <= r; i++)
        for (pair<int, int> p : g[i])
            merge(p.first, p.second);
    res += solve(l, mid);
    restore(h);
    h = hfa.size();
    for (int i = l; i <= mid; i++)
        for (pair<int, int> p: g[i])
            merge(p.first, p.second);
    res += solve(mid + 1, r);
    restore(h);
    return res;
}

signed main() {
    cin >> n;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        g[w].push_back({u, v});
    }
    for (int i = 1; i <= n; i++)
        p[i] = i, sz[i] = 1;
    cout << solve(1, n) << endl;
    return 0;
}