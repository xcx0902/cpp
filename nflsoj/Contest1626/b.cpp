#include <bits/stdc++.h>
using namespace std;

int m, n;
pair<string, int> s[1005];
string mp[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string translate(int x) {
    int p1, p2, p3;
    p1 = x / 100;
    p2 = x / 10 % 10;
    p3 = x % 10;
    if (p1 == 0 && p2 == 0) return mp[p3];
    else if (p1 == 0) return mp[p2] + mp[p3];
    else return mp[p1] + mp[p2] + mp[p3];
}

int main() {
    cin >> m >> n;
    for (int i = m; i <= n; i++)
        s[i] = {translate(i), i};
    sort(s + m, s + n + 1);
    cout << s[m].second << " " << s[n].second << endl;
    return 0;
}
