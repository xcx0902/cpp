#include <vector>

template <typename tp>
tp _sum(tp a, tp b) {
	return a + b;
};

template <typename tp>
void _spread(unsigned ll, unsigned lr, unsigned rl, unsigned rr, tp& lzy, tp& ldat, tp& rdat, tp& llzy, tp& rlzy) {
	if (lzy) {
		ldat += lzy * (lr - ll + 1);
		rdat += lzy * (rr - rl + 1);
		llzy += lzy;
		rlzy += lzy;
		lzy = 0;
	}
}

template <typename tp>
void _change(unsigned l, unsigned r, tp& dat, tp& lzy, tp cg) {
	dat += cg * (r - l + 1);
	lzy += cg;
}

template
<
    typename tp = long long,
    tp (*op)(tp a, tp b) = _sum,
    void (*spread)(unsigned ll, unsigned lr, unsigned rl, unsigned rr, tp& lzy, tp& ldat, tp& rdat, tp& llzy, tp& rlzy) = _spread,
    void (*chg)(unsigned l, unsigned r, tp& dat, tp& lzy, tp cg) = _change
>
class SegmentTree {
	private:
		struct Node {
			unsigned l, r;
			tp dat, lazy;
		};
		unsigned sz;
		std::vector<Node> t;

	public:
		SegmentTree() {}

		SegmentTree(unsigned _sz) {
			sz = _sz << 2;
			t = std::vector<Node>(sz);
		}

		void build(tp *a, unsigned l, unsigned r, unsigned p = 1) {
			t[p].l = l, t[p].r = r;
			if (l == r) {
				t[p].dat = a[l];
				return;
			}
			unsigned mid = l + r >> 1;
			build(a, l, mid, p << 1);
			build(a, mid + 1, r, p << 1 | 1);
			t[p].dat = op(t[p << 1].dat, t[p << 1 | 1].dat);
		}

		void change(unsigned l, unsigned r, tp d, unsigned p = 1) {
			if (l <= t[p].l && r >= t[p].r) {
				chg(t[p].l, t[p].r, t[p].dat, t[p].lazy, d);
				return;
			}
			spread(t[p << 1].l, t[p << 1].r, t[p << 1 | 1].l, t[p << 1 | 1].r, t[p].lazy, t[p << 1].dat, t[p << 1 | 1].dat, t[p << 1].lazy, t[p << 1 | 1].lazy);
			unsigned mid = t[p].l + t[p].r >> 1;
			if (l <= mid) change(l, r, d, p << 1);
			if (r > mid) change(l, r, d, p << 1 | 1);
			t[p].dat = op(t[p << 1].dat, t[p << 1 | 1].dat);
		}

		tp query(unsigned l, unsigned r, unsigned p = 1) {
			if (l <= t[p].l && r >= t[p].r)return t[p].dat;
			spread(t[p << 1].l, t[p << 1].r, t[p << 1 | 1].l, t[p << 1 | 1].r, t[p].lazy, t[p << 1].dat, t[p << 1 | 1].dat, t[p << 1].lazy, t[p << 1 | 1].lazy);
			tp left = 0, right = 0;
			unsigned mid = t[p].l + t[p].r >> 1;
			if (l <= mid) left = query(l, r, p << 1);
			if (r > mid) right = query(l, r, p << 1 | 1);
			return op(left, right);
		}
};
