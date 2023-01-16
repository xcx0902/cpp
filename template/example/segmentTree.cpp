#include <bits/stdc++.h>
#include "../segmentTree.h"
using namespace std;

int pushup(int x, int y) {
    return x + y;
}

void change(int &x, int y) {
    x += y;
}

SegmentTree<int, pushup, change> t;

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
            int x, p;
            cin >> x >> p;
            t.update(x, p);
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