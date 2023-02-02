#include <bits/stdc++.h>
using namespace std;

int n, w, ans = 0x3f3f3f3f, c[20], now[20];

void dfs(int id, int cnt) {
    if (cnt >= ans)
        return;
    if (id == n + 1) {
        ans = cnt;
        return;
    }
    for (int i = 1; i <= cnt; i++)
        if (now[i] + c[id] <= w) {
            now[i] += c[id];
            dfs(id + 1, cnt);
            now[i] -= c[id];
        }
    now[cnt + 1] = c[id];
    dfs(id + 1, cnt + 1);
    now[cnt + 1] = 0;
}

int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    sort(c + 1, c + n + 1, greater<int>());
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}