#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s + " ";
    for (int i = 1; i <= n; i++)
        if (s[i] == 'n' && s[i + 1] == 'a')
            cout << "nya", i++;
        else cout << s[i];
    cout << endl;
    return 0;
}