#include <bits/stdc++.h>
using namespace std;

const int N = 1030;
struct node { int cnt, v, w; } a[N];
vector<node> gp[N << 1];
int n, m, g, f[N << 1][N], vis[N];

int main() {
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].cnt >> a[i].v >> a[i].w;
        if (a[i].cnt == 0) a[i].cnt = m / a[i].w;
    }
    cin >> g;
    for (int i = 1, k; i <= g; i++) {
        cin >> k;
        for (int j = 1, t; j <= k; j++) {
            cin >> t;
            vis[t] = 1;
            gp[i].push_back(a[t]);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            gp[++g].push_back(a[i]);
    for (int i = 1; i <= g; i++)
        for (node j: gp[i])
            for (int k = 0; k <= j.cnt; k++)
                for (int l = k * j.w; l <= m; l++)
                    f[i][l] = max(f[i][l], f[i - 1][l - k * j.w] + k * j.v);
    if (f[g][m] < 0) cout << "i'm sorry..." << endl;
    else cout << f[g][m] << endl;
    return 0;
}