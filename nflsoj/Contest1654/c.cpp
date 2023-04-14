#include <bits/stdc++.h>
using namespace std;

const int N = 133333 + 5, M = 133333 + 5;

struct query { int id, l, r, t; } q[M];
struct update { int pos, col, pre; } u[M];
int n, m, sq, l = 1, r = 0, t, res, qcnt, ucnt, a[N], lst[N], cnt[N * 10], ans[N];

inline int cmp(query x, query y) {
    if (x.l / sq == y.l / sq)
        return (x.r / sq == y.r / sq) ? (x.t < y.t) : (x.r / sq < y.r / sq);
    else return x.l / sq < y.l / sq;
}

void modify(int t, int flag) {
    if (flag == 1) {
        a[u[t].pos] = u[t].col;
        if (l <= u[t].pos && u[t].pos <= r) {
            if ((--cnt[u[t].pre]) == 0) --res;
            if ((++cnt[u[t].col]) == 1) ++res;
        }
    } else {
        a[u[t].pos] = u[t].pre;
        if (l <= u[t].pos && u[t].pos <= r) {
            if ((--cnt[u[t].col]) == 0) --res;
            if ((++cnt[u[t].pre]) == 1) ++res;
        }
    }
}

void add(int x) {
    if ((++cnt[a[x]]) == 1)
        res++;
}

void del(int x) {
    if ((--cnt[a[x]]) == 0)
        res--;
}

int main() {
    cin >> n >> m;
    sq = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i], lst[i] = a[i];
    for (int i = 1, x, y; i <= m; i++) {
        char s[3];
        scanf("%s%d%d", s, &x, &y);
        if (s[0] == 'Q') q[++qcnt] = (query){qcnt, x, y, ucnt};
        else u[++ucnt] = (update){x, y, lst[x]}, lst[x] = y;
    }
    sort(q + 1, q + qcnt + 1, cmp);
    for (int i = 1; i <= qcnt; i++) {
        while (t < q[i].t) modify(++t, 1);
        while (t > q[i].t) modify(t--, -1);
        while (r < q[i].r) add(++r);
        while (l > q[i].l) add(--l);
        while (r > q[i].r) del(r--);
        while (l < q[i].l) del(l++);
        ans[q[i].id] = res;
    }
    for (int i = 1; i <= qcnt; i++)
        printf("%d\n", ans[i]);
    return 0;
}
