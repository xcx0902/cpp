#include <bits/stdc++.h>
#define bl(x) ((x - 1) / block + 1)
using namespace std;

const int N = 100005;
struct query { int l, r, lca, id; } q[N];
int n, m, l, r, cur, block, a[N], b[N], cnt[N], ans[N], vis[N];

bool cmp(query a, query b) {
    if (bl(a.l) != bl(b.l)) return bl(a.l) < bl(b.l);
    if (bl(a.l) & 1) return bl(a.r) > bl(b.r);
    else return bl(a.r) < bl(b.r);
}

void add(int x) {
    cnt[a[x]]++;
    if (cnt[a[x]] == 1) cur++;
} 

void del(int x) {
    cnt[a[x]]--;
    if (cnt[a[x]] == 0) cur--;
}

void calc(int x) {
    if (vis[x]) del(x);
    else add(x);
    vis[x] ^= 1;
}

namespace Graph {

int k, sz[N], top[N], dep[N], fa[N], son[N], dfn[N * 2], st[N], ed[N];
vector<int> g[N];

void dfs1(int u, int f) {
    sz[u] = 1, dep[u] = dep[f] + 1, fa[u] = f;
    st[u] = ++k, dfn[k] = u;
    for (int v: g[u]) 
        if (v != f) {
            dfs1(v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[son[u]])
                son[u] = v;
        }
    ed[u] = ++k, dfn[k] = u;
}

void dfs2(int u, int topx) {
    top[u] = topx;
    if (!son[u]) return;
    dfs2(son[u], topx);
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    return u;
}

}

using Graph::g;
using Graph::lca;
using Graph::dfs1;
using Graph::dfs2;
using Graph::dfn;
using Graph::st;
using Graph::ed;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    block = sqrt(n * 2);
    for (int i = 1, u, v, x; i <= m; i++) {
        cin >> u >> v;
        if (st[u] > st[v]) swap(u, v);
        x = lca(u, v);
        if (x == u || x == v) q[i] = {st[u], st[v], 0, i};
        else q[i] = {ed[u], st[v], x, i};
    }
    l = 1, r = 0;
    sort(q + 1, q + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        while (l < q[i].l) calc(dfn[l++]);
        while (l > q[i].l) calc(dfn[--l]);
        while (r < q[i].r) calc(dfn[++r]);
        while (r > q[i].r) calc(dfn[r--]);
        if (q[i].lca) calc(q[i].lca);
        ans[q[i].id] = cur;
        if (q[i].lca) calc(q[i].lca);
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
    return 0;
}