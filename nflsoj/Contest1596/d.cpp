#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int V, n, m, ans, c[N], v[N], f[N];

int main() {
	cin >> V >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		for (int j = 1; j <= m; j++)
            cin >> c[j] >> v[j];
		for (int j = V; j >= 0; j--)
            for (int k = 1; k <= m; k++)
                if (j >= c[k])
                    f[j] = max(f[j], f[j - c[k]] + v[k]);
	}
	cout << f[V] << endl;
    return 0;
}