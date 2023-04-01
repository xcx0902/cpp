#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1, t; i <= n; i++) {
        cin >> t;
        s.insert(t);
    }
    if (s.size() < 2) cout << "NO" << endl;
    else cout << *(++s.begin()) << endl;
    return 0;
}
