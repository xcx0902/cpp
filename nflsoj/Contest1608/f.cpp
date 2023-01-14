#include <bits/stdc++.h>
using namespace std;

const int N = 2000005, p = 1e9 + 7;
int n, m, a[N], c[N], f[N], s[N];

int get(int x) {
    int ans = 0;
    for (; x >= 1; x -= x & -x) (ans += c[x]) %= p;
    return ans;
}

void update(int x, int t) {
    for (; x <= m; x += x & -x) (c[x] += t) %= p;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i], a[i] = s[i];
    sort(a, a + n + 1);
    m = unique(a, a + n + 1) - a;
    for (int i = 0; i <= n; i++) s[i] = lower_bound(a, a + m, s[i]) - a + 1;
    update(s[0], 1);
    for (int i = 1; i <= n; i++) f[i] = get(s[i]), update(s[i], f[i]);
    cout << f[n] << endl;
    return 0;
}