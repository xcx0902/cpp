#include <vector>

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
