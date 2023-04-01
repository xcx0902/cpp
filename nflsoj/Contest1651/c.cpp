#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, ans, v[8][8];
char a[8][8];
string str;

clock_t st;

bool judge(string s) {
    if (s.size() & 1) return 0;
    // 0 1 2 3 (4)
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != '(' || s[s.size() - i - 1] != ')')
            return 0;
    return 1;
}

void dfs(int x, int y) {
    if (1.0 * (clock() - st) / CLOCKS_PER_SEC > 0.95) {
        cout << ans << endl;
        exit(0);
    }
    if (v[x][y] || x < 1 || x > n || y < 1 || y > n) return;
    str += a[x][y];
    if (judge(str)) ans = max(ans, (int)str.size());
    v[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        dfs(a, b);
    }
    str.pop_back();
    v[x][y] = 0;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    // cerr << "Input done" << endl;
    st = clock();
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}
