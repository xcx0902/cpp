#include <bits/stdc++.h>
using namespace std;

int n, m, ans1, ans2, a[200005];
map<string, int> mp;
vector<int> cnt;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++) {
        string s; cin >> s;
        mp[s]++;
    }
    for (auto p: mp)
        cnt.push_back(p.second);
    sort(cnt.begin(), cnt.end(), greater<int>());
    sort(a + 1, a + n + 1);
    for (int i = 0; i < cnt.size(); i++)
        ans1 += a[i + 1] * cnt[i];
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 0; i < cnt.size(); i++)
        ans2 += a[i + 1] * cnt[i];
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
