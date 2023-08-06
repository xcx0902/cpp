#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005;
int k, p, pr[N];
bool v[N], mk[20000005];

void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (!v[i]) pr[++pr[0]] = i;
        for (int j = 1; j <= pr[0] && (i * pr[j]) <= n; j++) {
            v[i * pr[j]] = 1;
            if (i % pr[j] == 0) break;
        }
    }
}

int IE(int i, int k, int s, int sign) {
    if (pr[i] == p)
        return sign * k / s;
    int ret = IE(i + 1, k, s, sign);
    if (s * pr[i] <= k)
        ret += IE(i + 1, k, s * pr[i], -sign);
    return ret;
}

signed main() {
    cin >> k >> p;
    if (k == 1) {
        cout << p << endl;
        return 0;
    }
    if (p * p > 1e9) {
        cout << 0 << endl;
        return 0;
    }
    init(p);
    if (p > 50) {
        for (int i = 1; i < pr[0]; i++)
            for (int j = pr[i]; j <= 1e9 / p; j += pr[i])
                mk[j] = 1;
        for (int i = 1, num = 0; p * i <= 1e9; i++) {
            if (!mk[i]) num++;
            if (num == k) {
                cout << p * i << endl;
                return 0;
            }
        }
    } else {
        int l = 2, r = 1e9 / p + 1, mid, ans;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (IE(1, mid, 1, 1) >= k) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        cout << (p * ans <= 1e9? p * ans : 0) << endl;
    }
    return 0;
}
