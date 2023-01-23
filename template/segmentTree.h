#ifndef _SEGMENT_TREE_H
#define _SEGMENT_TREE_H

#include <vector>

#define l(_p) t[_p].l
#define r(_p) t[_p].r
#define dat(_p) t[_p].dat
#define lazy(_p) t[_p].lazy
#define lson(_p) ((_p) << 1)
#define rson(_p) ((_p) << 1 | 1)

// Simple segment tree with single-point update and segment query
template <
    class T,
    T (*pushup)(T l, T r),
    void (*change)(T &p, T delta)
>
class SegmentTree {
    private:
        struct Node {
            unsigned l, r;
            T dat = T();
        };
        unsigned sz;
        std::vector<Node> t;

    public:
        SegmentTree() {}
        SegmentTree(unsigned sz) {
            sz <<= 2;
            t.resize(sz);
        }

        void resize(unsigned sz) {
            sz <<= 2;
            t.resize(sz);
        }

        void build(unsigned l, unsigned r, unsigned p = 1) {
            l(p) = l, r(p) = r;
            if (l == r) return;
            unsigned mid = (l + r) >> 1;
            build(l, mid, lson(p));
            build(mid + 1, r, rson(p));
        }

        void build(T *a, unsigned l, unsigned r, unsigned p = 1) {
            l(p) = l, r(p) = r;
            if (l == r) {
                dat(p) = a[l];
                return;
            }
            unsigned mid = (l + r) >> 1;
            build(a, l, mid, lson(p));
            build(a, mid + 1, r, rson(p));
            dat(p) = pushup(dat(lson(p)), dat(rson(p)));
        }

        void update(unsigned x, T delta, unsigned p = 1) {
            if (l(p) == r(p)) {
                change(dat(p), delta);
                return;
            }
            unsigned mid = (l(p) + r(p)) >> 1;
            if (x <= mid) update(x, delta, lson(p));
            else update(x, delta, rson(p));
            dat(p) = pushup(dat(lson(p)), dat(rson(p)));
        }

        T query(unsigned l, unsigned r, unsigned p = 1) {
            if (l <= l(p) && r(p) <= r)
                return dat(p);
            T lft = T(), rgt = T();
            unsigned mid = (l(p) + r(p)) >> 1;
            if (l <= mid) lft = query(l, r, lson(p));
            if (r > mid) rgt = query(l, r, rson(p));
            return pushup(lft, rgt);
        }
};

// Lazy segment tree with segment update and segment query
template <
    class Tdat, class Tlazy,
    Tdat (*pushup)(Tdat, Tdat),
    void (*pushdown)(unsigned, unsigned, Tdat&, Tdat&, Tlazy&, Tlazy&, Tlazy&),
    void (*change)(unsigned, unsigned, Tdat&, Tlazy&, Tdat)
>
class LazySegmentTree {
    private:
        struct Node {
            unsigned l, r;
            Tdat dat = Tdat();
            Tlazy lazy = Tlazy();
        };
        unsigned sz;
        std::vector<Node> t;

    public:
        LazySegmentTree() {}
        LazySegmentTree(unsigned sz) {
            sz <<= 2;
            t.resize(sz);
        }

        void resize(unsigned sz) {
            sz <<= 2;
            t.resize(sz);
        }

        void build(unsigned l, unsigned r, unsigned p = 1) {
            l(p) = l, r(p) = r;
            if (l == r) return;
            unsigned mid = (l + r) >> 1;
            build(l, mid, lson(p));
            build(mid + 1, r, rson(p));
        }

        void build(Tdat *a, unsigned l, unsigned r, unsigned p = 1) {
            l(p) = l, r(p) = r;
            if (l == r) {
                dat(p) = a[l];
                return;
            }
            unsigned mid = (l + r) >> 1;
            build(a, l, mid, lson(p));
            build(a, mid + 1, r, rson(p));
            dat(p) = pushup(dat(lson(p)), dat(rson(p)));
        }

        void update(unsigned x, Tdat delta, unsigned p = 1) {
            if (l(p) == r(p)) {
                change(l(p), r(p), dat(p), lazy(p), delta);
                return;
            }
            pushdown(l(p), r(p), dat(lson(p)), dat(rson(p)), lazy(p), lazy(lson(p)), lazy(rson(p)));
            unsigned mid = (l(p) + r(p)) >> 1;
            if (x <= mid) update(x, delta, lson(p));
            else update(x, delta, rson(p));
            dat(p) = pushup(dat(lson(p)), dat(rson(p)));
        }

        void secupdate(unsigned l, unsigned r, Tdat delta, unsigned p = 1) {
            if (l <= l(p) && r(p) <= r) {
                change(l(p), r(p), dat(p), lazy(p), delta);
                return;
            }
            pushdown(l(p), r(p), dat(lson(p)), dat(rson(p)), lazy(p), lazy(lson(p)), lazy(rson(p)));
            unsigned mid = (l(p) + r(p)) >> 1;
            if (l <= mid) secupdate(l, r, delta, lson(p));
            if (r > mid) secupdate(l, r, delta, rson(p));
            dat(p) = pushup(dat(lson(p)), dat(rson(p))); 
        }

        Tdat query(unsigned l, unsigned r, unsigned p = 1) {
            if (l <= l(p) && r(p) <= r)
                return dat(p);
            pushdown(l(p), r(p), dat(lson(p)), dat(rson(p)), lazy(p), lazy(lson(p)), lazy(rson(p)));
            Tdat lft = Tdat(), rgt = Tdat();
            unsigned mid = (l(p) + r(p)) >> 1;
            if (l <= mid) lft = query(l, r, lson(p));
            if (r > mid) rgt = query(l, r, rson(p));
            return pushup(lft, rgt);
        }
};

#undef l
#undef r
#undef dat
#undef lazy
#undef lson
#undef rson

#endif // _SEGMENT_TREE_H