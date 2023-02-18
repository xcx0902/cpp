#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int n, m, ans, price[N], weight[N], pos[N];
queue<int> waiting;
bool vis[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> price[i];
    for (int i = 1; i <= m; i++)
        cin >> weight[i];
    for (int i = 1, k; i <= 2 * m; i++) {
        cin >> k;
        if (k > 0) {
            bool ok = 0;
            for (int j = 1; j <= n; j++)
                if (!vis[j]) {
                    ok = 1, vis[j] = 1, pos[k] = j;
                    ans += price[j] * weight[k];
                    break;
                }
            if (!ok) waiting.push(k);
        } else {
            k = -k;
            vis[pos[k]] = 0;
            if (!waiting.empty()) {
                int p = waiting.front(); waiting.pop();
                vis[pos[k]] = 1, pos[p] = pos[k];
                ans += price[pos[k]] * weight[p];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
