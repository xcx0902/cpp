#include <bits/stdc++.h>
using namespace std;

int n;
string t, a[50];
char mtx[4][9] = {"***ABCDE", "FGHIJKLM", "NOPQRSTU", "VWXYZ***"};
char ans[4][9] = {"********", "********", "********", "********"};
map<char, pair<int, int>> pos;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> t;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
            if (mtx[i][j] != '*')
                pos[mtx[i][j]] = {i, j};
    for (int i = 1; i <= n; i++) {
        string x = a[i];
        if (x.size() <= t.size()) continue;
        bool flag = 1;
        for (int j = 0; j < t.size(); j++)
            if (x[j] != t[j]) {
                flag = 0;
                break;
            }
        if (flag) {
            pair<int, int> p = pos[x[t.size()]];
            ans[p.first][p.second] = x[t.size()];
        }
    }
    for (int i = 0; i < 4; i++, cout << endl)
        for (int j = 0; j < 8; j++)
            cout << ans[i][j];
    return 0;
}