#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int t, l, r, tmp[3], c[256], sum[N][3];
string s;

int main() {
    c['C'] = 0, c['O'] = 1, c['W'] = 2;
    cin >> s;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < 3; j++)
            sum[i][j] += sum[i - 1][j];
        sum[i][c[s[i - 1]]]++;
    }
    cin >> t;
    while (t--) {
        cin >> l >> r;
        for (int i = 0; i < 3; i++)
            tmp[i] = (sum[r][i] - sum[l - 1][i]) & 1;
        // cerr << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;
        cout << ((tmp[0] && !tmp[1] && !tmp[2] || !tmp[0] && tmp[1] && tmp[2])? 'Y' : 'N');
    }
    return 0;
}
