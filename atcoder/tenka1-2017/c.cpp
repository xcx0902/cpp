#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 1; i <= 3500; i++)
        for (int j = 1; j <= 3500; j++) {
            // cerr << i << " " << j << endl;
            // 1/i + 1/j + 1/x = 4/n
            // ij + ix + jx = (4ij/n)x
            // ij = (4ij/n - i - j)x
            if (4 * i * j % n) continue;
            int p = i * j, q = 4 * i * j / n - i - j;
            if (q == 0 || p % q || p / q < 0) continue;
            cout << i << " " << j << " " << p / q << endl;
            return 0;
        }
    return 0;
}
