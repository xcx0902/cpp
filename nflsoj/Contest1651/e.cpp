#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int n, ans;

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

bool judge(int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7)
            return 0;
        x /= 10;
    }
    return 1;
}

dsu d(N);

signed main() {
    cin >> n;
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        if (!judge(w)) d.merge(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (d.find(i) == i) {
            int s = d.size(i);
            if (s >= 3) ans += s * (s - 1) * (s - 2);
            ans += 2 * s * (s - 1) * (n - s);
        }
    cout << n * (n - 1) * (n - 2) - ans << endl;
    return 0;
}