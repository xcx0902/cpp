#include <bits/stdc++.h>
using namespace std;

int r, c, n, q, x, y, lstx, lsty, homex, homey, a[105][105]; // {r, 1} => {x, y}
int mp[105][105];
vector<int> dams;

int main() {
    freopen("dat03.in", "r", stdin);
    freopen("dat03.ans", "w", stdout);
    cin >> r >> c >> n >> q;
    x = r, y = 1;
#define sv lstx = x, lsty = y
    for (int i = 1; i <= n; i++) {
        char dir; int k;
        cin >> dir >> k;
        if (dir == 'R') {
            for (int i = 1; i <= k; i++)
                sv, y++, mp[x][y]++;
        } else if (dir == 'L') {
            for (int i = 1; i <= k; i++)
                sv, y--, mp[x][y]++;
        } else if (dir == 'U') {
            for (int i = 1; i <= k; i++)
                sv, x--, mp[x][y]++;
        } else if (dir == 'D') {
            for (int i = 1; i <= k; i++)
                sv, x++, mp[x][y]++;
        }
    }
    homex = x, homey = y;
    mp[x][y]--;
    x = lstx, y = lsty;
    // for (int i = 1; i <= r; i++, cerr << endl)
    //     for (int j = 1; j <= c; j++)
    //         cerr << mp[i][j] << " ";
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++) {
            if (mp[i][j] || (i == homex && j == homey) || (i == r && j == 1)) continue;
            a[i][j] = mp[i - 1][j - 1] + mp[i - 1][j] + mp[i - 1][j + 1] + mp[i][j - 1] + mp[i][j + 1] + mp[i + 1][j - 1] + mp[i + 1][j] + mp[i + 1][j + 1]; 
            dams.push_back(a[i][j]);
        }
    sort(dams.begin(), dams.end(), greater<int>());
    // for (int i = 0; i < dams.size(); i++)
    //     cerr << dams[i] << " ";
    // cerr << endl;
    while (q--) {
        int k, tot = 0;
        cin >> k;
        for (int i = 0; i < dams.size(); i++) {
            tot += dams[i];
            if (tot >= k) {
                cout << i + 1 << endl;
                goto end;
            }
        }
        cout << "DIE" << endl;
        end:;
    }
    return 0;
}
