#include <bits/stdc++.h>
using namespace std;

const int N = 300001;
int n, d, p, id = 1, ans, a[N], lst[N];

int main() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // cout << "Input done" << endl;
    for (int i = 1; i <= n; i++) {
        if (a[i]) lst[i] = p = i;
        else lst[i] = p;
    }
    // cout << "Init done" << endl;
    while (id < n) {
        // cout << id << endl;
        while (lst[min(n, id + d)] > id)
            id = lst[min(n, id + d)];
        if (id == n) break;
        ans++, id += d;
    }
    cout << ans << endl;
    return 0;
}