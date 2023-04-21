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

const int N = 100005;

struct node { int u, v, w; } a[N], b[N];
bool cmp(node x, node y) { return x.w < y.w; }

int i, j, p, q, n, m, r = 1, c = 1, fa, fb;
int ans = 0, maxn = 0;

dsu d1(N), d2(N);

void solveR() {
    fa = d1.find(a[r].u);
    fb = d1.find(a[r].v);
    if (fa != fb) {
        d1.merge(fa, fb);
        m--, ans += n * a[r].w;
    }
    r++;
}

void solveC() {
    fa = d2.find(b[c].u);
    fb = d2.find(b[c].v);
    if (fa != fb) {
        d2.merge(fa, fb);
        n--, ans += m * b[c].w;
    }
    c++;
}

signed main() {
    cin >> n >> m >> p >> q;
    for (i = 1; i <= p; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
        maxn += a[i].w * n;
    }
    for (i = 1; i <= q; i++) {
        cin >> b[i].u >> b[i].v >> b[i].w;
        maxn += b[i].w * m;
    }
    sort(a + 1, a + p + 1, cmp);
    sort(b + 1, b + q + 1, cmp);
    while ((m > 1) && (n > 1)) {
        if (a[r].w < b[c].w) solveR();
        else solveC();
    }
    while (m > 1) solveR();
    while (n > 1) solveC();
    cout << maxn - ans << endl;
    return 0;
}
