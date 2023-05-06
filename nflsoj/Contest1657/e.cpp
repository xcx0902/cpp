#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
int tr[2000005];
bool f[26];
const int Z = 1e6;
void add(int x, int y) {
    for (int i = x; i <= 2e6; i += lowbit(i)) tr[i] = min(tr[i], y);
}
int query(int x) {
    int res = 2e6;
    for (int i = x; i; i -= lowbit(i)) res = min(res, tr[i]);
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int ans = -1;
    for (int i = 0; i < s.size(); i++) f[s[i] - 'a'] = 1;
    for (char c = 'a'; c <= 'z'; c++) {
        if (!f[c - 'a'])
            continue;
        memset(tr, 0x3f, sizeof tr);
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c)
                sum++;
            else
                sum--;
            ans = max(ans, i - query(sum + Z - 1));
            add(sum + Z, i);
        }
    }
    if (ans > 1)
        cout << ans << endl;
    else
        cout << -1;
    return 0;
}
