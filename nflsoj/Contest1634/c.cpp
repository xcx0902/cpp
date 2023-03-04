#include <bits/stdc++.h>
using namespace std;

string s, a, b;
int sp;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'I' || s[i] == 'V') {
            sp = i;
            break;
        }
    for (int i = 0; i < s.size(); i++)
        if (i < sp) a += s[i];
        else b += s[i];
    if (a == "LX") a = "XL";
    if (b == "VI") b = "IV";
    if (a == "X" && b == "I") a = "", b = "IX";
    if (a == "XX" && b == "I") a = "X", b = "IX";
    if (a == "XXX" && b == "I") a = "XX", b = "IX";
    if (a == "LX" && b == "I") a = "L", b = "IX";
    if (a == "LXX" && b == "I") a = "XL", b = "IX";
    if (a == "LXXX" && b == "I") a = "LXX", b = "IX";
    cout << a + b << endl;
    return 0;
}
