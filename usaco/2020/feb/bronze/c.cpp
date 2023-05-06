#include <bits/stdc++.h>
using namespace std;

int n, k, a1, b1, a2, b2, s, a[105], b[105];

bool judge() {
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

int findCycle() {
    int ret = 0;
    memcpy(b, a, sizeof a);
    do {
        reverse(a + a1, a + a2 + 1);
        reverse(a + b1, a + b2 + 1);
        ret++;
    } while (!judge());
    return ret;
}

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    cin >> n >> k >> a1 >> a2 >> b1 >> b2;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    s = findCycle();
    for (int i = 1; i <= k % s; i++) {
        reverse(a + a1, a + a2 + 1);
        reverse(a + b1, a + b2 + 1);
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << endl;
    return 0;
}
