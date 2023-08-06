#include <bits/stdc++.h>
using namespace std;

int n, cnt, op, ans;
bool first = 1, del[10001];
struct node {
    int a, b;
    bool operator < (node x) const {
        if (a != x.a) return a < x.a;
        else return b < x.b;
    }
} f[10001];
set<pair<double, double>> s;
set<node> t;

pair<double, double> slv(node x, node y) {
    // (x.a - y.a)x = (y.b - x.b)
    if (x.a - y.a == 0 && y.b - x.b == 0) return {114514, 1919810};
    if (x.a - y.a == 0) return {1919810, 114514};
    double ansx = 1.0 * (y.b - x.b) / (x.a - y.a);
    double ansy = x.a * ansx + x.b;
    return {ansx, ansy};
}

int calc(int x) {
    int ret = 0;
    s.clear(); t.clear();
    for (int i = 1; i <= cnt; i++)
        if (!del[i] && i != x)
            t.insert(f[i]);
    if (t.count(f[x])) return -1;
    for (auto p: t) {
        pair<double, double> tmp = slv(p, f[x]);
        if (tmp == pair<double, double>{114514, 1919810}) ret--;
        else if (tmp == pair<double, double>{1919810, 114514}) ;
        else s.insert(tmp);
    }
    return ret + s.size();
}

int main() {
    // freopen("output.txt", "w", stdout);
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            cnt++;
            f[cnt].a = a, f[cnt].b = b;
            ans += calc(cnt) + 1;
            if (first) ans++, first = 0;
        } else {
            int k, tmp = 0;
            cin >> k;
            del[k] = 1;
            ans -= calc(k) + 1;
            // for (int i = 1; i <= cnt; i++) {
            //     if (!del[i]) tmp++;
            //     if (tmp == k) {
            //         del[i] = 1;
            //         ans -= calc(i) + 1;
            //         break;
            //     }
            // }
        }
        end: cout << ans << endl;
        // cout << "del: ";
        // for (int i = 1; i <= cnt; i++)
        //     cout << del[i] << " ";
        // cout << endl;
    }
    return 0;
}