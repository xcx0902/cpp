#include <bits/stdc++.h>
using namespace std;

int n;
double h[255], t[255], f[255];

namespace subtask1 {
double ans;
void dfs(int x, int basic, int add, int mxadd, double p) {
    if (x > n) {
        ans += (basic + mxadd) * p;
        return;
    }
#define harmony(_p) dfs(x + 1, basic + 2, add + 1, max(mxadd, add + 1), _p)
#define tune(_p) dfs(x + 1, basic + 1, add + 1, max(mxadd, add + 1), _p)
#define fail(_p) dfs(x + 1, basic, 0, mxadd, _p)
#define judge(_i, _j) (fabs((_i) - (_j)) < 1e-8)
    if (judge(h[x], 1)) harmony(p);
    if (judge(t[x], 1)) tune(p);
    if (judge(f[x], 1)) fail(p);
    if (judge(h[x], 0.5)) harmony(p / 2);
    if (judge(t[x], 0.5)) tune(p / 2);
    if (judge(f[x], 0.5)) fail(p / 2);
}
void solve() {
    dfs(1, 0, 0, 0, 1);
    cout << ans << endl;
}
bool judge_if_sub1() { // Is it subtask1?
    for (int i = 1; i <= n; i++)
        if (!judge(f[i], 0))
            return 1;
    return 0;
}
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i] >> t[i] >> f[i];
    subtask1::solve();
    return 0;
}
