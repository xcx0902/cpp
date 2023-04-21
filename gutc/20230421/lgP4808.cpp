#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 1e4 + 5;

unordered_map<int, int> f;
int n, m = M, a[M];

int dfs(int n) {
    // if (n < m) return a[n];
    if (f.count(n)) return f[n];
    int ans = 0;
    for (int l = 2, r = 0; l <= n; l = r + 1) {
        r = n / (n / l);
        ans += dfs(n / l) * (r - l + 1);
    }
    return f[n] = ans;
}

signed main() {
    cin >> n;
    m = min(n, m);
    a[1] = 1, f[1] = 1;
    // for (int i = 2; i < m; i++)
    //     for (int l = 2, r; l <= i; l = r + 1) {
    //         r = i / (i / l);
    //         a[i] += a[i / l] * (r - l + 1);
    //     }
    cout << dfs(n) << endl;
    return 0;
}
