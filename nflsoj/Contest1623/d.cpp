#include <bits/stdc++.h>
using namespace std;

int n, s[3], t[3];
string a, b;

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        s[a[i] - 'a']++, t[b[i] - 'a']++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            if (s[j] && j + 'a' != b[i]) {
                s[j]--, t[b[i] - 'a']--;
                if (s[0] + s[1] < t[2] || s[0] + s[2] < t[1] || s[1] + s[2] < t[0])
                    s[j]++, t[b[i] - 'a']++;
                else {
                    cout << char(j + 'a');
                    break;
                }
            }
    return 0;
}