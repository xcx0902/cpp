#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> a, b, c;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
        sort(s.begin(), s.end());
        b.push_back(s);
        reverse(s.begin(), s.end());
        c.push_back(s);
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
        sort(a[i].begin(), a[i].end());
        cout << lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1 << " ";
        reverse(a[i].begin(), a[i].end());
        cout << upper_bound(b.begin(), b.end(), a[i]) - b.begin() << endl;
    }
    return 0;
}
