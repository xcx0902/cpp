#include <bits/stdc++.h>
using namespace std;

struct node {
    int a, b, id;
    bool operator<(const node &x) {
        return a + max(b, x.a) + x.b < x.a + max(x.b, a) + b;
    }
};

const int N = 1005;
int n, fa, fb;
node x[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) x[i].id = i;
    for (int i = 1; i <= n; i++) cin >> x[i].a;
    for (int i = 1; i <= n; i++) cin >> x[i].b;
    sort(x + 1, x + n + 1);
    fa = x[1].a, fb = fa + x[1].b;
    for (int i = 2; i <= n; i++) {
        fb = max(fa + x[i].a, fb) + x[i].b;
        fa += x[i].a;
    }
    cout << fb << endl;
    for (int i = 1; i <= n; i++) cout << x[i].id << " ";
    cout << endl;
    return 0;
}
