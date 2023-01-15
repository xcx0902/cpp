#include <vector>
using std::vector;

template <typename tp>
class fenwickTree {
    private:
        vector<tp> c; // from 1 to N
        unsigned sz;
        unsigned lowbit(unsigned x) {
            return x & (-x);
        }

    public:
        fenwickTree() {
        }

        fenwickTree(unsigned _sz) {
            c = vector<tp> (_sz + 1);
            sz= _sz;
        }

        tp getsum(unsigned dx) { // return sum of [1..dx] 
            tp ret = 0;
            while(dx) {
                ret += c[dx];
                dx -= lowbit(dx);
            }
            return ret;
        }

        tp sum(unsigned l, unsigned r) { // return sum of [l..r]
            return getsum(r) - getsum(l - 1);
        }

        tp get(unsigned dx) { // return value[dx]
            return sum(dx, dx);
        }

        tp add(unsigned dx, tp val) { // return after add
            unsigned tmp = dx;
            while(dx <= sz) {
                c[dx] += val;
                dx += lowbit(dx);
            }
            return c[tmp];
        }

        tp change(unsigned dx, tp val) { // return after change
            return add(dx, val - get(dx));
        }
};
