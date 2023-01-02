#include <bits/stdc++.h>
using namespace std;

int n;
const double eps = 1e-8;
double a[105][105];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++) {
		int pos = i;
		for (int j = i + 1; j <= n; j++)
			if (fabs(a[pos][i]) < fabs(a[j][i])) 
				pos = j;
		for (int j = 1; j <= n + 1; j++)
			swap(a[i][j], a[pos][j]);
		if (fabs(a[i][i]) < eps) {
			cout << "No Solution" << endl;
			return 0;
		}
		for (int j = n + 1; j >= i; j--)
			a[i][j] /= a[i][i];
		for (int j = 1; j <= n; j++)
			if (j != i)
				for (int k = n + 1; k >= i; k--)
					a[j][k] -= a[j][i] * a[i][k];
	}
	for (int i = 1; i <= n; i++)
		cout << fixed << setprecision(2) << a[i][n + 1] << endl;
	return 0;
}