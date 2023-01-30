#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int, int>> ans;

signed main() {
    int n;
    cin >> n;
    for (int i = 2; i <= 200000; i++) {
        // (L + L + i - 1) * i / 2 = n
        // L + L = n * 2 / i + 1 - i;
        if (n * 2 % i) continue;
        int L = n * 2 / i + 1 - i;
        if (L % 2) continue;
        L /= 2;
        if (L <= 0) continue;
        ans.push_back({L, L + i - 1});
    }
    sort(ans.begin(), ans.end(), greater<pair<int, int>>());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}