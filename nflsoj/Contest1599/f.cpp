#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int t, n, f[N][2];
vector<int> g[N];

void dfs(int u, int fa) {
    int s = 0;
    multiset<int> st;
    f[u][0] = 1, f[u][1] = 0;
    for (int v: g[u]) 
        if (v != fa) {
            dfs(v, u);
            s += f[v][0];
            st.insert(f[v][1] - f[v][0]);
        }
    if (st.size() == 0) return;
    if (st.size() == 1) f[u][0] = min(f[u][0] + s, s + *st.begin() + 1);
    else if (st.size() >= 2) {
        int a = *st.begin(), b = *(++st.begin());
        f[u][0] = min(f[u][0] + s, s + a + b + 1);
    }
    f[u][1] = s + *st.begin();
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        cout << min(f[1][0], f[1][1] + 1) << endl;
    }
    return 0;
}