#include <bits/stdc++.h>
using namespace std;

int n, q, op, x, yellow[105], red[105];

int main() {
    cin >> n >> q;
    while (q--) {
        cin >> op >> x;
        if (op == 1) yellow[x]++;
        if (op == 2) red[x]++;
        if (op == 3) {
            if (yellow[x] >= 2 || red[x] >= 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
