#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int w, n, tw, tt, t[N], c[N], cost[1 << N], f[1 << N];

int main() {
    cin >> w >> n;
    for (int i = 0; i < n; i++) cin >> t[i] >> c[i];
    for (int S = 0; S < (1 << n); S++) {
        tw = tt = 0;
        for (int i = 0; i < n; i++)
            if (S & (1 << i))
                tw += c[i], tt = max(tt, t[i]);
        if (tw <= w)
            cost[S] = tt;
        else
            cost[S] = 0x3f3f3f3f;
    }
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int S = 0; S < (1 << n); S++)
        for (int T = S; T; T = (T - 1) & S) f[S] = min(f[S], f[S ^ T] + cost[T]);
    cout << f[(1 << n) - 1] << endl;
    return 0;
}