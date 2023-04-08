#include <bits/stdc++.h>
using namespace std;

const int N = 500000 + 5, M = 500000 + 5;

struct query { int id, l, r, t; } q[M];
struct update { int pos, col, pre; } u[M];
int n, m, k, sq, l = 1, r = 0, t, qcnt, ucnt;
int a[N], b[N], tot[N], lst[N], cnt[N * 10], ans[N];

inline int cmp(query x, query y) {
    if (x.l / sq == y.l / sq)
        return (x.r / sq == y.r / sq) ? (x.t < y.t) : (x.r / sq < y.r / sq);
    else return x.l / sq < y.l / sq;
}

void add(int p) {
	--tot[cnt[p]];
	++tot[++cnt[p]];
}

void del(int p) {
	--tot[cnt[p]];
	++tot[--cnt[p]];
}

void modify(int t, int flag) {
    if (flag == 1) {
        a[u[t].pos] = u[t].col;
        if (l <= u[t].pos && u[t].pos <= r) {
            del(u[t].pre);
            add(u[t].col);
        }
    } else {
        a[u[t].pos] = u[t].pre;
        if (l <= u[t].pos && u[t].pos <= r) {
            del(u[t].col);
            add(u[t].pre);
        }
    }
}

int main() {
    cin >> n >> m;
    sq = pow(n, 0.666);
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[++k] = a[i], lst[i] = a[i];
    for (int i = 1, op, x, y; i <= m; i++) {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) q[++qcnt] = (query){qcnt, x, y, ucnt};
        else {
            b[++k] = y;
            u[++ucnt] = (update){x, y, lst[x]}, lst[x] = y;
        }
    }
    // cerr << "K = " << k << endl;
    sort(b + 1, b + k + 1);
    k = unique(b + 1, b + k + 1) - b - 1;
    // cerr << "K after unique = " << k << endl;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(b + 1, b + k + 1, a[i]) - b;
    for (int i = 1; i <= ucnt; i++)
        u[i].col = lower_bound(b + 1, b + k + 1, u[i].col) - b;
    for (int i = 1; i <= ucnt; i++)
        u[i].pre = lower_bound(b + 1, b + k + 1, u[i].pre) - b;
    // for (int i = 1; i <= n; i++)
    //     cerr << a[i] << " ";
    // cerr << endl;
    // for (int i = 1; i <= ucnt; i++)
    //     cerr << u[i].pos << " " << u[i].col << " " << u[i].pre << endl;
    sort(q + 1, q + qcnt + 1, cmp);
    for (int i = 1; i <= qcnt; i++) {
        while (t < q[i].t) modify(++t, 1);
        while (t > q[i].t) modify(t--, -1);
        while (r < q[i].r) add(a[++r]);
        while (l > q[i].l) add(a[--l]);
        while (r > q[i].r) del(a[r--]);
        while (l < q[i].l) del(a[l++]);
        ans[q[i].id] = 1;
        while (tot[ans[q[i].id]])
            ans[q[i].id]++;
    }
    for (int i = 1; i <= qcnt; i++)
        printf("%d\n", ans[i]);
    return 0;
}
