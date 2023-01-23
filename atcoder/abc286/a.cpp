#include <bits/stdc++.h>
using namespace std;

int n, p, q, r, s, a[101];

int main() {
    cin >> n >> p >> q >> r >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = p; i <= q; i++)
        swap(a[i], a[i + r - p]);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}