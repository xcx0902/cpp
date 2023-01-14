#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = INT_MAX;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i * 3 + j * 5 == n)
                ans = min(ans, i + j);
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}