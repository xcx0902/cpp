#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (char i: s)
        cout << (i == '0'? 1 : 0);
    cout << endl;
    return 0;
}
