#include <bits/stdc++.h>
using namespace std;

int n, k, lst, a[300005];
map<int, int> mp;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= k; i++) {
        if (i > n) break;
        if (mp[a[i]]) {k++; continue;}
        mp[a[i]] = 1;
    }
    for (int i = 0; ; i++) {
        if (mp[i]) continue;
        cout << i << endl;
        return 0;
    }
    return 0;
}
