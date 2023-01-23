#include <bits/stdc++.h>
using namespace std;

int n, l = 1, r = 1, ans, a[100001];
map<int, int> mp;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (r <= n && l <= r) {
        if (mp[a[r]]) mp[a[l++]]--;
        else mp[a[r]]++, ans = max(ans, r - l + 1), r++;
    }
    cout << ans << endl;
    return 0;
}