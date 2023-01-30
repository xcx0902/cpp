#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 300005;
int n, ans, ok[N];
string s[N];

namespace trie {

int tot, trie[N][26], ed[N], g[35][35], ind[26];
queue<int> q;

void insert(string s) {
    int p = 0;
    for (char c: s) {
        if (!trie[p][c - 'a'])
            trie[p][c - 'a'] = ++tot;
        p = trie[p][c - 'a'];
    }
    ed[p] = 1;
}

void topo() {
    q = queue<int>();
    for (int i = 0; i < 26; i++)
        if (!ind[i])
            q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < 26; v++)
            if (g[u][v] && (!(--ind[v])))
                q.push(v);
    }
}

bool check(string s) {
    memset(g, 0, sizeof g);
    memset(ind, 0, sizeof ind);
    int p = 0;
    for (char c: s) {
        c -= 'a';
        if (ed[p]) return 0; // substr
        for (int j = 0; j < 26; j++)
            if (j != c && trie[p][j] && !g[c][j])
                g[c][j] = 1, ind[j]++;
        p = trie[p][c];
    }
    topo();
    for (int i = 0; i < 26; i++)
        if (ind[i]) // circle
            return 0;
    return 1;
}

}; // namespace trie

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i], trie::insert(s[i]);
    for (int i = 1; i <= n; i++)
        if (trie::check(s[i]))
            ans++, ok[i] = 1;
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (ok[i])
            cout << s[i] << endl;
    return 0;
}