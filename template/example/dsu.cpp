#include <bits/stdc++.h>
#include "../dsu.h"
using namespace std;

int n, q;
dsu f;

int main() {
    cin >> n >> q;
    f = dsu(n);
    while (q--) {
        char op;
        cin >> op;
        if (op == 'F') {
            int x;
            cin >> x;
            cout << f.find(x) << endl;
        } else if (op == 'M') {
            int x, y;
            cin >> x >> y;
            f.merge(x, y);
            cout << "OK" << endl;
        } else if (op == 'S') {
            int x;
            cin >> x;
            cout << f.size(x) << endl;
        } else {
            cout << "Invalid" << endl;
        }
    }
    return 0;
}