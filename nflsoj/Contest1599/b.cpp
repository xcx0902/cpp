#include <bits/stdc++.h>
using namespace std;

int n;
string s[1005];

int main() {
    while (cin >> s[++n]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= s[i].size(); j++) {
            bool f = 0;
            string temp = s[i].substr(0, j);
            for (int k = 1; k <= n; k++) {
                if (k == i) continue;
                if (temp == s[k].substr(0, j)) { f = 1; break; }
            }
            if (!f || temp == s[i]) {
                cout << s[i] << " " << temp << endl;
                break;
            }
        }
    return 0;
}