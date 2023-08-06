#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int n, b;
struct node {
    int p, v, id;
    bool operator < (node x) const {
        return p < x.p;
    }
} a[N];
map<int, int> f;

int main() {
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i].p >> a[i].v;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        a[i].id = i;
    f[1] = a[1].v;
    for (int i = 2; i <= n; i++) {
        int lst = lower_bound(a + 1, a + n + 1, (node){a[i].p - b, 0, 0}) - a - 1;
        f[i] = max(f[i - 1], f[lst] + a[i].v);
    }
    cout << f[n] << endl;
    return 0;
}