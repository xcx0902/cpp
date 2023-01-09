#include <bits/stdc++.h>
using namespace std;

double exp() {
    char s[100];
    cin >> s;
    if (s[0] == '+') return exp() + exp();
    if (s[0] == '-') return exp() - exp();
    if (s[0] == '*') return exp() * exp();
    if (s[0] == '/') return exp() / exp();
    return atof(s);
}

int main() {
    cout << fixed << setprecision(6) << exp() << endl;
    return 0;
}