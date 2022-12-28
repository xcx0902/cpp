#include <iostream>
#define lowbit(x) ((x) & (-(x)))
#define sum(l,r) (getsum(r)-getsum((l)-1))
#define get(x) (sum(x,x))
#define change(x,y) (add(x,(y)-(get(x))))
using namespace std;

const int N = 1024 + 5;
int n, m, t, c[N][N];

int getsum(int x, int y) {
	int ret = 0;
	for (int p = x; p >= 1; p -= lowbit(p))
		for (int q = y; q >= 1; q -= lowbit(q))
			ret += c[p][q];
	return ret;
}

void add(int x, int y, int d) {
	for (int p = x; p <= n; p += lowbit(p))
		for (int q = y; q <= n; q += lowbit(q))
			c[p][q] += d;
	return;
}

int main() {
	while (cin >> t && t != 3) {
		if (t == 0) scanf("%d", &n);
		else if (t == 1) {
			int x, y, d;
			scanf("%d%d%d", &x, &y, &d);
			add(x, y, d);
		} else {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			printf("%d\n", getsum(x2, y2) - getsum(x1 - 1, y2) - getsum(x2, y1 - 1) + getsum(x1 - 1, y1 - 1)); 
		}
	}
	return 0;
}
