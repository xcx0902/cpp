#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int n, d, ans = 0x3f3f3f3f, a[N], f[N][10005], mn[N];
deque<int> q;

void get(int ori[], int dest[], int k, bool flag) {
    q.clear();
    for (int i = 1; i <= 10000; i++) {
        while (q.size() && q.front() + k <= i) q.pop_front();
        if (flag) while (q.size() && ori[i] > ori[q.back()]) q.pop_back();
        else while (q.size() && ori[i] < ori[q.back()]) q.pop_back();
        q.push_back(i);
        dest[i] = ori[q.front()];
    }
}

int main() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 10000; j++)
            f[i][j] = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10000; j++)
            f[i][j] = min(f[i][j], mn[min(10000, j + d)] + abs(a[i] - j));
            // for (int k = max(1, j - d); k <= min(10000, j + d); k++)
            //     f[i][j] = min(f[i][j], f[i - 1][k] + abs(a[i] - j));
        get(f[i], mn, 2 * d + 1, 0);
        // for (int j = 1; j <= 10; j++)
        //     cout << f[i][j] << " ";
        // cout << "| ";
        // for (int j = 1; j <= 10; j++)
        //     cout << mn[j] << " ";
        // cout << endl;
    }
    for (int i = 1; i <= 10000; i++) {
        ans = min(ans, f[n][i]);
    }
    cout << ans << endl;
    return 0;
}