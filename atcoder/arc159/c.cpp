#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, sum, ans, p, a[N], t[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];
    if (sum % n && (sum + n * (n + 1) / 2) % n) {
        cout << "No" << endl;
        return 0;
    }
    if (sum % n != 0) {
        p = 1;
        sum += n * (n + 1) / 2;
        for (int i = 1; i <= n; i++)
            a[i] += i;
    }
    sum /= n;
    for (int i = 1; i <= n; i++)
        if (a[i] > sum)
            ans += a[i] - sum;
    cout << "Yes" << endl << ans * 2 + p << endl;
    if (p) {
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
        cout << endl;
    }
    for (int _ = 1; _ <= ans; _++) {
        int x = 0, y = 0, cnt = 2;
        for (int i = 1; i <= n; i++) {
            if (a[i] < sum) x = i;
            if (a[i] > sum) y = i;
        }
        cerr << "x = " << x << ", y = " << y << endl;
        t[x] = 1, t[y] = 2;
        for (int i = 1; i <= n; i++)
            if (i != x && i != y)
                t[i] = ++cnt;
        for (int i = 1; i <= n; i++)
            cout << n - t[i] + 1 << ' ';
        cout << endl;
        t[x] = 2, t[y] = 1;
        for (int i = 1; i <= n; i++)
            cout << t[i] << ' ';
        cout << endl;
        a[x]++, a[y]--;
        for (int i = 1; i <= n; i++)
            cerr << "a[" << i << "] = " << a[i] << " ";
        cerr << endl;
    }
    return 0;
}