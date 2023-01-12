#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int f[100001];

signed main() {
	cin >> n;
	if (n * (n + 1) / 2 & 1) {
		cout << 0 << endl;
		return 0;
	}
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = n * (n + 1) / 4; j >= i; j--)
//			f[j] = max(f[j], f[j - i] + i);
			f[j] += f[j - i];
	cout << f[n * (n + 1) / 4] / 2 << endl;
	return 0;
}