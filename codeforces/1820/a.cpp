#include <bits/stdc++.h>
using namespace std;

int t, ans;
string s;

int main() {
    cin >> t;
    while (t--) {
        cin >> s;
        if (s.size() == 1 && s[0] == '^') {
            cout << 1 << endl;
            goto end;
        }
        ans = (s[0] == '_') + (s[s.size() - 1] == '_');
        for (int i = 0; i < s.size() - 1; i++)
            ans += (s[i] == '_') & (s[i + 1] == '_');
        cout << ans << endl;
        end:;
    }
    return 0;
}
