#include <bits/stdc++.h>
using namespace std;

int n;
string s[1005];

int main() {
    while (cin >> s[++n]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= s[i].size(); j++) {
            bool f = 0;
            string t = s[i].substr(0, j);
            for (int k = 1; k <= n; k++) {
                if (k == i) continue;
                if (t == s[k].substr(0, j)) { f = 1; break; }
            }
            if (!f || t == s[i]) {
                cout << s[i] << " " << t << endl;
                break;
            }
        }
    return 0;
}