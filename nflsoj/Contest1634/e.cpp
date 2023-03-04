#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, k, tmp, cnt, dep[N];
bool vis[N], ans[N];
map<int, int> mk[N];
vector<int> final, g[N];

void dfs(int u, int lst, int h) {
    vis[u] = 1, dep[u] = h;
    for (int v: g[u]) {
        if (vis[v]) continue;
        if (mk[u][v] == 2) {
            ans[v] = 1, ans[lst] = 0;
            dfs(v, v, h + 1);
        } else dfs(v, lst, h + 1);
    }
}

void findmin(int u) {
    for (int v: g[u]) {
        if (dep[v] < dep[u]) continue;
        tmp = min(tmp, v);
        findmin(v);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mk[u][v] = mk[v][u] = w;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1, 1);
    for (int i = 1; i <= n; i++)
        if (ans[i])
            cnt++;
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
        if (ans[i]) {
            tmp = i, findmin(i);
            final.push_back(tmp);
        }
    sort(final.begin(), final.end());
    for (int i: final)
        cout << i << " ";
    cout << endl;
    return 0;
}