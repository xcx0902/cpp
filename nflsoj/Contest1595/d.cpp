#include <bits/stdc++.h>
using namespace std;

int n, tot, now, a[505], f[505][100005];

int main() {
	memset(f, -0x7f, sizeof f);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], tot += a[i];
	f[0][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= tot; j++)
			f[i][j] = max(f[i - 1][j], max(f[i - 1][j + a[i]] + a[i], f[i - 1][abs(j - a[i])] + a[i]));
	cout << tot - f[n][0] / 2 << endl;
	return 0;
}