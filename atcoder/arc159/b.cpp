#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}

int dfs(int x, int y) {
    if (abs(x - y) == 1) return min(x, y);
    if (!x || !y) return 0;
    if (x == y) return 1;
    if (gcd(x, y) > 1) return dfs(x / gcd(x, y) - 1, y / gcd(x, y) - 1) + 1;
    int d = abs(x - y), val = min(d, min(x, y));
    for (int i = 1; i <= d / i; i++)
        if (d % i == 0) {
            if (x % i == y % i && gcd((x - x % i), (y - y % i)) > 1 && i > 1)
                val = min(val, x % i);
            int j = d / i;
            if (x % j == y % j && gcd((x - x % j), (y - y % j)) > 1 && j > 1)
                val = min(val, x % j);
        }
    return dfs(x - val, y - val) + val;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << dfs(x, y) << endl;
    return 0;
}
