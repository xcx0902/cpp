#include <bits/stdc++.h>
using namespace std;

string s;
int st = -1, x, y, tmp, flag, sump, sumq;
vector<int> p, q;
bool fx[8005], fy[8005];

int main() {
    cin >> s >> x >> y;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != 'F') {
            x -= i, st = i;
            break;
        }
    if (st == -1) {
        if (x == (int)s.size() && y == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    for (int i = st; i < s.size(); ) {
        flag ^= 1, tmp = 0;
        i++;
        while (i < s.size() && s[i] == 'F') tmp++, i++;
        if (flag) q.push_back(tmp);
        else p.push_back(tmp);
    }
    fx[0] = fy[0] = 1;
    for (int i = 0; i < p.size(); i++)
        for (int j = 8000; j >= p[i]; j--)
            fx[j] |= fx[j - p[i]];
    for (int i = 0; i < q.size(); i++)
        for (int j = 8000; j >= q[i]; j--)
            fy[j] |= fy[j - q[i]];
    for (int i: p) sump += i;
    for (int i: q) sumq += i;
    if ((sump - x) % 2 == 0 && fx[(sump - x) / 2] && (sumq - y) % 2 == 0 && fy[(sumq - y) / 2]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
