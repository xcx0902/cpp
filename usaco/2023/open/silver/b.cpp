#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
int m, n, a[N], c[N], ans[N];
bool v[N];

inline int ppc(int x) {
    int ret = 0;
    while (x) {
        ret += (x & 1);
        x >>= 1;
    }
    return ret;
}

bool cmp(int x, int y) {
    return ppc(x) > ppc(y);
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            char c; while ((c = getchar()) == '\n');
            a[i] = a[i] * 2 + (c == 'G');
        }
        v[a[i]] = 1;
    }
    for (int i = 0; i < (1 << m); i++)
        c[i] = i;
    sort(c, c + (1 << m), cmp);
    for (int i = 1; i <= n; i++) {
        if (ans[a[i]]) {
            printf("%d\n", ans[a[i]]);
            continue;
        }
        for (int j = 0; j < (1 << m); j++)
            if (v[a[i] ^ c[j]]) {
                printf("%d\n", (ans[a[i]] = ppc(c[j])));
                break;
            }
    }
    return 0;
}
