#include <bits/stdc++.h>
#define int long long
#define X(_p) sc[_p]
#define Y(_p) f[_p]
#define K(_p) (s + st[_p])
using namespace std;

const int N = 3e5 + 5;
int n, s, l = 1, r, sc[N], st[N], f[N], q[N];

int binarySearch(int l, int r, long long k) {
    int mid = 0, ans = r;
    while (l <= r) {
        mid = (l + r) >> 1; 
        if (Y(q[mid + 1]) - Y(q[mid]) > k * (X(q[mid + 1]) - X(q[mid])))
            r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    return q[ans];
}

signed main() {
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> st[i] >> sc[i];
        st[i] += st[i - 1], sc[i] += sc[i - 1];
    }
    q[++r] = 0;
    for (int i = 1; i <= n; i++) {
        int p = binarySearch(l, r, K(i));
        f[i] = f[p] + s * (sc[n] - sc[p]) + st[i] * (sc[i] - sc[p]);
        while (l < r && (Y(q[r]) - Y(q[r - 1])) * (X(i) - X(q[r])) 
                     >= (X(q[r]) - X(q[r - 1])) * (Y(i) - Y(q[r]))) --r;
        q[++r] = i;
    }
    cout << f[n] << endl;
    return 0;
}

