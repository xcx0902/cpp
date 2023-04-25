#include <vector>
using std::vector;

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

template <typename tp>
class BIT_2D {
    private:
        vector<vector<tp>> c;
        unsigned sz;
        unsigned lowbit(unsigned x) { return x & (-x); }

    public:
        BIT_2D() {}
        BIT_2D(unsigned _sz) {
            c = vector<vector<tp>>(_sz + 1);
            for (unsigned i = 1; i <= _sz; i++)
                c[i] = vector<tp>(_sz + 1);
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
