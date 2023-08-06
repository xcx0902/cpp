#include <bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7;
int n, k, a[101], f[1001];

int dfs(int sum) {
    if (sum > k) return 0;
    if (f[sum]) return f[sum];
    int ret = 1;
    for (int i = 1; i <= 100; i++)
        if (a[i])
            ret = (ret + dfs(sum + i) * a[i]) % p;
    return f[sum] = ret;
}

int main() {
    cin >> n >> k;
    for (int i = 1, x; i <= n; i++)
        cin >> x, a[x]++;
    cout << dfs(0) << endl;
    return 0;
}