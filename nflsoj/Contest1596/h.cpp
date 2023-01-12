#include <bits/stdc++.h>
using namespace std;

int n, m, t, ans, a[1001]; 
pair<int, int> f[1001][1001];

pair<int, int> add(pair<int, int> p, int q) {
	if (p.second + q > t) return {p.first + 1, q};
	else return {p.first, p.second + q};
}

void debug() {
	pair<int, int> x = add({2, 2}, 2);
	cout << x.first << " " << x.second << endl;
}

int main() {
//	debug();
	cin >> n >> t >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			f[i][j] = {998244353, 998244353};
	for (int i = 0; i <= n; i++) 
		f[i][0] = {1, 0};
	for (int i = 1; i <= n; i++/*, cout << endl*/)
		for (int j = 1; j <= i; j++) {
			f[i][j] = f[i - 1][j];
			if (a[i] > t) goto ed;
			 f[i][j] = min(f[i][j], add(f[i - 1][j - 1], a[i])); 
//			cout << f[i][j].first << " " << f[i][j].second << " | "; 
			ed: if (f[i][j].first <= m) ans = max(ans, j);
		}
	cout << ans << endl;
	return 0;
}