#include <bits/stdc++.h>
using namespace std;

int n, ans[1 << 20];
pair<int, int> a[1 << 20];
map<int, int> cnt, sum;

int main() {
    cin >> n;
    for (int i = 0; i < 1 << n; i++)
        cin >> a[i].first, a[i].second = i, cnt[a[i].first]++;
    // cerr << "INPUT DONE" << endl;
    sum[cnt.begin()->first] = cnt.begin()->second;
    // cerr << "LINE " << __LINE__ << endl;
    for (auto p = ++cnt.begin(); p != cnt.end(); p++) {
        auto it = p, it2 = p;
        // cerr << p->first << " " << p->second << endl;
        // cerr << (--it)->first << endl;
        sum[p->first] = sum[(--it2)->first] + p->second;
    }
    // cerr << "LINE " << __LINE__ << endl;
    sort(a, a + (1 << n));
    // cerr << "LINE " << __LINE__ << endl;
    // cerr << "INIT DONE" << endl;
    for (int i = 0; i < 1 << n; i++) {
        int less = sum[a[i].first] - 1;
        for (int j = 0; j <= n; j++)
            if ((1 << (n - j)) - 1 <= less) {
                ans[a[i].second] = j;
                break;
            }
    }
    for (int i = 0; i < 1 << n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}