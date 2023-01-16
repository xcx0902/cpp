#include <bits/stdc++.h>
using namespace std;

int n, p1, p2, p3, t1, t2, lst, ans, l[105], r[105], f[1445];

int main() {
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		for (int j = l[i]; j <= r[i]; j++)
			f[j] = 1;
	}
	for (int i = l[1]; i <= r[n]; i++) {
		if (!f[i]) lst++;
		else lst = 0;
		if (lst < t1) ans += p1;
		else if (lst < t1 + t2) ans += p2;
		else ans += p3;
	}
	cout << ans - p1 << endl;
	return 0;
}
