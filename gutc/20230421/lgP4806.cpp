#include <bits/stdc++.h>
#define int long long
using namespace std;

class dsu {
    private:
        std::vector<unsigned> f, sz;

    public:
        dsu() {}

        dsu(unsigned _sz) {
            f = sz = std::vector<unsigned>(_sz + 1);
            for (unsigned i = 1; i <= _sz; i++)
                f[i] = i, sz[i] = 1;
        }

        unsigned find(unsigned x) {
            if (f[x] == x) return x;
            return f[x] = find(f[x]);
        }

        void merge(unsigned x, unsigned y) {
            unsigned fx = find(x);
            unsigned fy = find(y);
            f[fx] = fy;
            sz[fy] += sz[fx];
        }

        bool same(unsigned x, unsigned y) {
            return find(x) == find(y);
        }

        unsigned size(unsigned x) {
            return sz[find(x)];
        }
};

const int N = 200005;

int n, m, d, tot, cnt, ans, mx;
struct node {
    int u, v, w;
    bool flag;  // 0: black, 1: white
    bool operator < (node a) const {
        return w < a.w || (w == a.w && flag < a.flag);
    }
} a[N], b[N];
dsu ds(N);

signed main() {
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++)
        cin >> a[i].u >> a[i].v >> a[i].w;
    for (int i = n; i <= m; i++)
        a[i].flag = 1;
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++) {
        int x = ds.find(a[i].u), y = ds.find(a[i].v);
        if (x != y) ds.merge(x, y), tot++;
        mx = max(mx, a[i].w);
        if (tot >= n - 1) break;
    }
    tot = 0; ds = dsu(N);
    for (int i = 1; i <= m; i++) {
        if (a[i].w >= mx) {
            b[++cnt] = {a[i].u, a[i].v, max(a[i]. w - d, 0LL), a[i].flag};
            continue;
        }
        int x = ds.find(a[i].u), y = ds.find(a[i].v);
        if (x != y) ds.merge(x, y), tot++, ans += a[i].flag;
    }
    sort(b + 1, b + cnt + 1);
    for (int i = 1; i <= cnt; i++) {
        int x = ds.find(b[i].u), y = ds.find(b[i].v);
        if (x != y) {ds.merge(x, y), tot++, ans += b[i].flag; break;}
    }
    for (int i = 1; i <= m; i++) {
        int x = ds.find(a[i].u), y = ds.find(a[i].v);
        if (x != y) ds.merge(x, y), tot++, ans += a[i].flag;
        if (tot >= n - 1) break;
    }
    cout << ans << endl;
    return 0;
}
