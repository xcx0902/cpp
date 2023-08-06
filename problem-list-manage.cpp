#include <bits/stdc++.h>
using namespace std;

string s;
map<string, int> mp;
int donecnt, doingcnt;

int main() {
    freopen("problems.txt", "r", stdin);
    while (getline(cin, s)) {
        int lft = -1, rgt = -1;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '(') {
                lft = i;
                break;
            }
        for (int i = s.size() - 1; i >= 0; i--)
            if (s[i] == ')') {
                rgt = i;
                break;
            }
        if (lft == -1 || rgt == -1) continue;
        mp[s.substr(lft + 1, rgt - lft - 1)]++;
        if (s.find("done") != string::npos) donecnt++;
        if (s.find("doing") != string::npos) doingcnt++;
    }
    cout << "Categories: " << endl;
    for (auto p: mp)
        cout << p.first << ": " << p.second << endl;
    cout << "Done: " << donecnt << endl;
    cout << "Doing: " << doingcnt << endl;
    return 0;
}
