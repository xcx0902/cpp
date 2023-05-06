#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005;
int n, t, p, f[2][N];
char s[N];

int main() {
    cin >> n >> t >> s;
    for (int i = 0; i < n; i++)
        f[0][i] = s[i] - '0';
    for (int k = 0; k < 60; k++)
        if (t & (1ll << k)) {
            int r = (1ll << k) % n, l = (n - r) % n;
            for (int i = 0; i < n; i++) {
                f[p ^ 1][i] = f[p][l] ^ f[p][r];
                if ((++l) >= n) l -= n;
                if ((++r) >= n) r -= n;
            }
            p ^= 1;
        }
    for (int i = 0; i < n; i++)
        cout << f[p][i];
    cout << endl;
    return 0;
}
