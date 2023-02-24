#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
string s;

int main() {
    cin >> n >> k;
    cin >> s;
    for (char c: s) {
        if (c == 'o') cnt++;
        if (cnt > k) cout << 'x';
        else {
            cout << c;
        }
    }
    return 0;
}
