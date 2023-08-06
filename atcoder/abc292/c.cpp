#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool mark[N];
int cnt, pr[N], d[N], num[N];

void init() {
    cnt = 0;
    d[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!mark[i])
            pr[++cnt] = i, num[i] = 1, d[i] = 2;
        for (int j = 1; j <= cnt && i * pr[j] < N; ++j) {
            mark[i * pr[j]] = 1;
            if (!(i % pr[j])) {
                num[i * pr[j]] = num[i] + 1;
                d[i * pr[j]] = d[i] / (num[i] + 1) * (num[i * pr[j]] + 1);
                break;
            }
            d[i * pr[j]] = d[i] * d[pr[j]];
            num[i * pr[j]] = 1;
        }
    }
}

int n, ans;

signed main() {
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans += d[i] * d[n - i];
    }
    cout << ans << endl;
    return 0;
}
