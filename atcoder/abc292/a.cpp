#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (char c: s) {
        cout << (char)toupper(c);
    }
    return 0;
}
