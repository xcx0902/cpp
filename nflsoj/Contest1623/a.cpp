#include <bits/stdc++.h>
using namespace std;

int n, sum, x, A, B, a[100];
multiset<int> s;

int main() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 2; j <= 9; j++)
            s.insert(j);
        s.insert(10); s.insert(10); s.insert(10);
        s.insert(11);
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i], s.erase(s.find(a[i]));
    if (sum > 21) return cout << "DOSTA" << endl, 0;
    x = 21 - sum;
    for (int i: s)
        if (i > x) A++;
        else B++;
    if (A >= B) cout << "DOSTA" << endl;
    else cout << "VUCI" << endl;
    return 0;
}