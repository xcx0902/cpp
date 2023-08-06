#include <bits/stdc++.h>
using namespace std;

const int N = 60005;
int n, m, k, tot, top1, top2, a[N], b[N], ans[N];
struct node { bool op; int l, r, k, id; } q[N << 1], tmp1[N << 1], tmp2[N << 1];

template <typename tp>
class BIT {
    private:
        vector<tp> c;  // from 1 to N
        unsigned sz;
        unsigned lowbit(unsigned x) { return x & (-x); }

    public:
        BIT() {}
        BIT(unsigned _sz) {
            c = vector<tp>(_sz + 1);
            sz = _sz;
        }
        tp getsum(unsigned dx) {  // return sum of [1..dx]
            tp ret = 0;
            while (dx) {
                ret += c[dx];
                dx -= lowbit(dx);
            }
            return ret;
        }
        tp sum(unsigned l, unsigned r) {  // return sum of [l..r]
            return getsum(r) - getsum(l - 1);
        }
        tp get(unsigned dx) {  // return value[dx]
            return sum(dx, dx);
        }
        tp add(unsigned dx, tp val) {  // return after add
            unsigned tmp = dx;
            while (dx <= sz) {
                c[dx] += val;
                dx += lowbit(dx);
            }
            return c[tmp];
        }
        tp change(unsigned dx, tp val) {  // return after change
            return add(dx, val - get(dx));
        }
};
BIT<int> bit(N);

void solve(int l, int r, int L, int R) {
    if (L > R || l > r) return;
    if (L == R) {
        for (int i = l; i <= r; i++)
            if (q[i].op)
                ans[q[i].id] = L;
        return;
    }
    int mid = (L + R) >> 1;
    int top1 = top2 = 0;
    for (int i = l; i <= r; i++) {
        if (q[i].op) {
            int t = bit.sum(q[i].l, q[i].r);
            if (t >= q[i].k) tmp1[++top1] = q[i];
            else q[i].k -= t, tmp2[++top2] = q[i];
        } else {
            if (q[i].k <= mid) tmp1[++top1] = q[i], bit.add(q[i].id, 1);
            else tmp2[++top2] = q[i];
        }
    }
    for (int i = 1; i <= top1; i++)
        if (!tmp1[i].op)
            bit.add(tmp1[i].id, -1);
    for (int i = 1; i <= top1; i++) q[l + i - 1] = tmp1[i];
    for (int i = 1; i <= top2; i++) q[l + top1 + i - 1] = tmp2[i];
    solve(l, l + top1 - 1, L, mid);
    solve(l + top1, r, mid + 1, R);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    k = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + k + 1, a[i]) - b;
        q[++tot].op = 0;
        q[tot].id = i;
        q[tot].k = a[i];
    }
    for (int i = 1; i <= m; i++) {
        ++tot;
        cin >> q[tot].l >> q[tot].r >> q[tot].k;
        q[tot].k = q[tot].r - q[tot].l + 1 - q[tot].k + 1;
        q[tot].op = 1;
        q[tot].id = i;
    }
    solve(1, tot, 1, k);
    for (int i = 1; i <= m; i++)
        cout << b[ans[i]] << endl;
    return 0;
}