#include <bits/stdc++.h>
#include "../fenwickTree.h"
using namespace std;

int n, q;
fenwickTree<int> t;

int main() {
    cin >> n >> q;
    t = fenwickTree<int>(n);
    while (q--) {
        char op;
        cin >> op;
        if (op == 'A') {
            int p, x;
            cin >> p >> x;
            t.add(p, x);
        } else if (op == 'C') {
            int p, x;
            cin >> p >> x;
            t.change(p, x);
        } else if (op == 'G') {
            int p;
            cin >> p;
            cout << t.get(p) << endl;
        } else if (op == 'S') {
            int l, r;
            cin >> l >> r;
            cout << t.sum(l, r) << endl;
        } else {
            cout << "Invalid" << endl;
        }
    }
    return 0;
}