#include <bits/stdc++.h>
using namespace std;

const int N = 500005, Q = 500005, M = 1000005;
int n, q, sq, sum[10005], a[N], ans[Q], cnt[M];
int l = 1, r = 0;
struct node {
    int l, r, id;
    bool operator < (const node &x) const {
        if (l / sq != x.l / sq) return l < x.l;
        if (l / sq & 1) return r < x.r;
        return r > x.r;
    }
} query[Q];

inline void add(int p){
    cnt[p]++;
    if (cnt[p] == 1) sum[p / sq]++;
}

inline void del(int p){
    cnt[p]--;
    if (cnt[p] == 0) sum[p / sq]--;
}

inline int mex() {
    for (int i = 1; i <= sq; i++)
        if (sum[i - 1] != sq)
            for (int j = (i - 1) * sq; j < i * sq; j++)
                if (!cnt[j])
                    return j;
}

int main() {
    scanf("%d%d", &n, &q);
    sq = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (a[i] > 2e5) a[i] = 2e5 + 1;
    }
    for (int i = 1; i <= q; i++)
        scanf("%d%d", &query[i].l, &query[i].r), query[i].id = i;
    sort(query + 1, query + q + 1);
    for (int i = 1; i <= q; i++) {
        while (l > query[i].l) add(a[--l]);
        while (r < query[i].r) add(a[++r]);
        while (l < query[i].l) del(a[l++]);
        while (r > query[i].r) del(a[r--]);
        ans[query[i].id] = mex();
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
    return 0;
}