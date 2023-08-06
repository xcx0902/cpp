#include <bits/stdc++.h>
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
            if (fx == fy) return;
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
int n, m, v[N], e[N];
pair<int, int> edges[N];
dsu s(N);

int main() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        edges[i] = {u, v};
        s.merge(u, v);
    }
    for (int i = 1; i <= n; i++)
        v[s.find(i)]++;
    for (int i = 1; i <= m; i++)
        e[s.find(edges[i].first)]++;
    for (int i = 1; i <= n; i++) {
        // cerr << v[i] << " " << e[i] << endl;
        if (v[i] != e[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
