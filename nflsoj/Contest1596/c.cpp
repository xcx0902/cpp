#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int V, n, f[10005], c[505], v[505], num[505];

int main() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) 
        cin >> num[i] >> c[i] >> v[i];
    for (int i = 1; i <= n; i++)
        for (int j = V; j >= c[i]; j--)
            for (int k = 0; k <= num[i] && k * c[i] <= j; k++)
                f[j] = max(f[j], f[j - k * c[i]] + k * v[i]);
    cout << f[V] << endl;
    return 0;
}