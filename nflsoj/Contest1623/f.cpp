#include <bits/stdc++.h>
using namespace std;

int n, m, fa[10005];

int find(int x) {
    while (x != fa[x]) x = fa[x];
    return fa[x];
}

void mkroot(int x) {
    int y = fa[x];
    fa[x] = x;
    while (x != y) {
        int tmp = fa[y];
        fa[y] = x;
        x = y;
        y = tmp;
    }
}

void connect(int x, int y) {
    if (find(x) == find(y)) return;
    mkroot(x), mkroot(y), fa[y] = x;
}

void destroy(int x, int y) {
    mkroot(x), fa[y] = y;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    while (m--) {
        string op;
        int x, y;
        cin >> op >> x >> y;
        if (op == "Connect") connect(x, y);
        if (op == "Destroy") destroy(x, y);
        if (op == "Query") cout << (find(x) == find(y)? "Yes" : "No") << endl;
    }
    return 0;
}