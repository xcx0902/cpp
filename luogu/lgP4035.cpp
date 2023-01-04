#include <bits/stdc++.h>
using namespace std;

const int N = 15;
double mtx[N][N], a[N][N], b[N];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 1; j <= n; j++)
            cin >> mtx[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            a[i][j] = 2 * (mtx[i][j] - mtx[i + 1][j]);
            b[i] += mtx[i][j] * mtx[i][j] - mtx[i + 1][j] * mtx[i + 1][j];
        }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++)
            if (fabs(a[j][i]) > 1e-8) {
                for (int k = 1; k <= n; k++)
                    swap(a[i][k], a[j][k]);
                swap(b[i], b[j]);
            }
        for (int j = 1; j <= n; j++) 
            if (i != j) {
                double rate = a[j][i] / a[i][i];
                for (int k = i; k <= n; k++)
                    a[j][k] -= a[i][k] * rate;
                b[j] -= b[i] * rate;
            }
    }
    for (int i = 1; i <= n; i++)
        cout << fixed << setprecision(3) << b[i] / a[i][i] << " ";
    cout << endl;
    return 0;
}