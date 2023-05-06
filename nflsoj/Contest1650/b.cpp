#include <bits/stdc++.h>
using namespace std;

const int N = 60005;
int n, m, k, tot, top1, top2, ans[N];
struct node { bool op; int x1, y1, x2, y2, k, id; } q[N << 1], tmp1[N << 1], tmp2[N << 1];

template <typename tp>
class BIT_2D {
    private:
        vector<vector<tp>> c;
        unsigned sz;
        unsigned lowbit(unsigned x) { return x & (-x); }

    public:
        BIT_2D() {}
        BIT_2D(unsigned _sz) {
            c.resize(_sz + 1);
            for (unsigned i = 1; i <= _sz; i++)
                c[i].resize(_sz + 1);
            sz = _sz;
        }
        tp getsum(unsigned dx, unsigned dy) {
            tp ret = 0;
            for (unsigned x = dx; x >= 1; x -= lowbit(x))
                for (unsigned y = dy; y >= 1; y -= lowbit(y))
                    ret += c[x][y];
            return ret;
        }
        tp sum(unsigned x1, unsigned y1, unsigned x2, unsigned y2) {
            return getsum(x2, y2) - getsum(x1 - 1, y2) - getsum(x2, y1 - 1) + getsum(x1 - 1, y1 - 1);
        }
        tp get(unsigned dx, unsigned dy) {
            return sum(dx, dy, dx, dy);
        }
        void add(unsigned dx, unsigned dy, tp val) {
            for (unsigned x = dx; x <= sz; x += lowbit(x))
                for (unsigned y = dy; y <= sz; y += lowbit(y))
                    c[x][y] += val;
        }
        void change(unsigned dx, unsigned dy, tp val) {
            add(dx, dy, val - get(dx, dy));
        }
};
BIT_2D<int> bit(505);

void solve(int l, int r, int L, int R) {
    // cerr << "Solving " << l << " " << r << " " << L << " " << R << endl;
    if (L > R || l > r) return;
    if (L == R) {
        for (int i = l; i <= r; i++)
            if (q[i].op)
                ans[q[i].id] = L;
        return;
    }
    int mid = (L + R) >> 1;
    int top1 = top2 = 0;
    // cerr << "Start operation" << endl;
    for (int i = l; i <= r; i++) {
        // cerr << "# Operate " << i << endl;
        if (q[i].op) {
            // cerr << "Before calc sum" << endl;
            int t = bit.sum(q[i].x1, q[i].y1, q[i].x2, q[i].y2);
            // cerr << "After calc sum" << endl;
            if (t >= q[i].k) tmp1[++top1] = q[i];
            else q[i].k -= t, tmp2[++top2] = q[i];
        } else {
            // cerr << "Before add " << q[i].x1 << " " << q[i].y1 << endl;
            if (q[i].k <= mid) tmp1[++top1] = q[i], bit.add(q[i].x1, q[i].y1, 1);
            else tmp2[++top2] = q[i];
            // cerr << "After add" << endl;
        }
    }
    for (int i = 1; i <= top1; i++)
        if (!tmp1[i].op)
            bit.add(tmp1[i].x1, tmp1[i].y1, -1);
    for (int i = 1; i <= top1; i++) q[l + i - 1] = tmp1[i];
    for (int i = 1; i <= top2; i++) q[l + top1 + i - 1] = tmp2[i];
    solve(l, l + top1 - 1, L, mid);
    solve(l + top1, r, mid + 1, R);
}
int main() {
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> x;
            q[++tot].op = 0;
            q[tot].id = 0;
            q[tot].k = x;
            q[tot].x1 = i;
            q[tot].y1 = j;
        }
    for (int i = 1; i <= m; i++) {
        ++tot;
        cin >> q[tot].x1 >> q[tot].y1;
        cin >> q[tot].x2 >> q[tot].y2;
        cin >> q[tot].k;
        q[tot].op = 1;
        q[tot].id = i;
    }
    solve(1, tot, 0, 2e9);
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
    return 0;
}