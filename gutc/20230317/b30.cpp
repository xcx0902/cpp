#include <bits/stdc++.h>
using namespace std;

int n, m, tmp, ans, l[15], r[15], a[15], b[15];
vector<int> ok[15];
bool vis[15];

void dfs(int x) {
    if (x > n) {
        ans = max(ans, tmp);
        return;
    }
    for (int i = 0; i < ok[x].size(); i++)
        if (!vis[ok[x][i]]) {
            vis[ok[x][i]] = 1;
            tmp++;
            dfs(x + 1);
            vis[ok[x][i]] = 0;
            tmp--;
        }
    dfs(x + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    for (int i = 1; i <= m; i++)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (l[i] <= a[j] && b[j] <= r[i])
                ok[i].push_back(j);
    dfs(1);
    cout << ans << endl;
    return 0;
}
