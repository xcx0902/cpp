#include <bits/stdc++.h>
using namespace std;

int n, mx, f = 1, flg = 1;
string s, a[1005];
int l[1005], r[1005];

// bool full_space(string x) {
//	for (char c: x)
//		if (c != ' ')
//			return 0;
//	return 1;
//}

int main() {
    while (getline(cin, a[++n]))
        ;
    n--;
    for (int i = 1; i <= n; i++) mx = max(mx, int(a[i].size()));
    for (int i = 1; i <= n; i++) {
        //		if (full_space(a[i])) {
        //			l[i] = mx - a[i].size();
        //			continue;
        //		}
        int diff = mx - a[i].size();
        if ((diff % 2) == 0)
            l[i] = r[i] = diff / 2;
        else {
            if (f)
                l[i] = (diff / 2), r[i] = (diff / 2) + 1;
            else
                l[i] = (diff / 2) + 1, r[i] = (diff / 2);
            f ^= 1;
        }
    }
    for (int i = 1; i <= mx + 2; i++) cout << "*";
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << "*";
        for (int j = 1; j <= l[i]; j++) cout << " ";
        cout << a[i];
        for (int j = 1; j <= r[i]; j++) cout << " ";
        cout << "*";
        cout << endl;
    }
    for (int i = 1; i <= mx + 2; i++) cout << "*";
    cout << endl;
    return 0;
}