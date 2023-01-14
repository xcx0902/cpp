#include <bits/stdc++.h>
using namespace std;

int pos, p, q;
string s, t;

int f(string x) {
    int ans = 0;
    for (int i = 0; i < x.size(); i++) ans += (x[i] == '+' ? 1 : -1);
    return ans;
}

void dfs(int u) {
    if (u == t.size()) {
        q++;
        if (f(t) == pos)
            p++;
        return;
    }
    if (t[u] == '?') {
        t[u] = '+', dfs(u + 1);
        t[u] = '-', dfs(u + 1);
        t[u] = '?';
    } else
        dfs(u + 1);
}

int main() {
    cin >> s >> t;
    pos = f(s);
    dfs(0);
    cout << fixed << setprecision(15) << 1.0 * p / q << endl;
    return 0;
}