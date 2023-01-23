#include <bits/stdc++.h>
#include "../segmentTree.h"
using namespace std;

int pushup(int x, int y) {
    return x + y;
}

void pushdown(unsigned l, unsigned r, int &ld, int &rd, int &add, int &ladd, int &radd) {
    if (add) {
        int mid = (l + r) >> 1;
        ladd += add, radd += add;
        ld += add * (mid - l + 1);
        rd += add * (r - mid);
        add = 0;
    }
}

void change(unsigned l, unsigned r, int &d, int &add, int delta) {
    d += (r - l + 1) * delta;
    add += delta;
}

LazySegmentTree<int, int, pushup, pushdown, change> t;

int n, q, a[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    t.resize(n + 5);
    t.build(a, 1, n);
    cin >> q;
    while (q--) {
        char opt;
        cin >> opt;
        if (opt == 'U') {
            int l, r, p;
            cin >> l >> r >> p;
            t.secupdate(l, r, p);
        } else if (opt == 'Q') {
            int l, r;
            cin >> l >> r;
            cout << t.query(l, r) << endl;
        } else {
            cout << "Invalid" << endl;
        }
    }
    return 0;
}