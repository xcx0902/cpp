#include <bits/stdc++.h>
using namespace std;

unordered_map<string, set<int>> mp;
string s[20001];
int n, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        s[i] = str;
        for (int j = 0; j < str.size(); j++) {
            string tmp;
            for (int k = j; k < str.size(); k++)
                mp[tmp += str[k]].insert(i);
        }
    }
    for (int i = 1; i <= n;i++)
        ans += mp[s[i]].size() - 1;
    cout << ans << endl;
    return 0;
}