#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 21) + 5;
int n, m, a[25], hit[N], pre[N];
queue<int> q;

void solve() {
    memset(hit, -1, sizeof hit);
    memset(pre, -1, sizeof pre);
    queue<int> q;
    q.push((1 << n) - 1);
    pre[(1 << n) - 1] = (1 << n) - 1;
    int flag = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        if (!u) { flag = 1; break; }
        for (int i = 0; i < n; i++)
            if ((1 << i) & u) {
                int v = u - (1 << i), nxt = 0;
                for (int j = 0; j < n; j++)
                    if (v & (1 << j))
                        nxt |= a[j];
                if (pre[nxt] == -1) {
                    pre[nxt] = u;
                    hit[nxt] = i;
                    q.push(nxt);
                }
            }
    }
    if (flag) {
        stack<int> st;
        int x = 0;
        while (x != (1 << n) - 1) {
            st.push(hit[x]);
            x = pre[x];
        }
        cout << st.size() << ": ";
        while (st.size()) {
            cout << st.top() << " ";
            st.pop();
        }
    } else cout << "Impossible";
    cout << endl;
}

int main() {
    while (cin >> n >> m && n + m) {
        memset(a, 0, sizeof a);
        for (int i = 1, u, v; i <= m; i++) {
            cin >> u >> v;
            a[u] |= (1 << v);
            a[v] |= (1 << u);
        }
        solve();
    }
    return 0;
}