#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> mp;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (!mp[s]) cout << "OK" << endl;
        else cout << s << mp[s] << endl;
        ++mp[s];
    }
    return 0;
} 
