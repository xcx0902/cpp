#include <bits/stdc++.h>
using namespace std;

int n, k, l = 1, r = 1, x, y, sz, ans, a[100005];
map<int, int> mp;
multiset<int> s;

void ins(int x) {
    if (mp[x] == 0) sz++;
    else s.erase(s.find(mp[x]));
    mp[x]++;
    s.insert(mp[x]);
}

void del(int x) {
    s.erase(s.find(mp[x]));
    mp[x]--;
    if (mp[x] == 0) sz--;
    else s.insert(mp[x]);
}

bool ok() {
    return sz <= k + 1;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ins(a[1]);
    while (r <= n) {
        if (l == x && r == y) break;
        x = l, y = r;
        if (r < n) ins(a[++r]);
        while (!ok()) del(a[l++]);
        ans = max(ans, *(--s.end()));
    }
    cout << ans << endl;
    return 0;
} 
