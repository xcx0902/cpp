#include <bits/stdc++.h>
using namespace std;

int v, n, f[20005];

int main() {
	cin >> v >> n;
	for (int i = 1, ci, vi; i <= n; i++) {
		cin >> ci >> vi;
		for (int j = v; j >= ci; j--)
            f[j] = max(f[j], f[j - ci] + vi);
	}	
	cout << f[v] << endl;
	return 0;
}
