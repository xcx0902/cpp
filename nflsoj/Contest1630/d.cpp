#include <bits/stdc++.h>
#define int long long
using namespace std;

int x, cnt, ans1, c[105];
__int128 ans2, f[105];

signed main() {
    f[1] = 1;
    for (int i = 2; i <= 100; i++)
        f[i] = f[i - 1] * i;
    while (scanf("%lld", &x) != EOF) {
        int n = x;
        cnt = ans1 = 0;
        memset(c, 0, sizeof c);
        for (signed i = 2; i * i <= n; i++)
            if (n % i == 0) {
                cnt++;
                while (n % i == 0)
                    n /= i, c[cnt]++, ans1++;
            }
        if (n > 1)
            c[++cnt]++, ans1++;
        ans2 = f[ans1];
        for (int i = 1; i <= cnt; i++)
            ans2 /= f[c[i]];
        long long tmp = ans2;
        printf("%lld %lld\n", ans1, tmp);
    }
    return 0;
}