#include <bits/stdc++.h>
using namespace std;

const int dx[6] = {1, -1, 0,  0, 0,  0};
const int dy[6] = {0,  0, 1, -1, 0,  0};
const int dz[6] = {0,  0, 0,  0, 1, -1};

const int N = 35;
struct node { int x, y, z; };
int l, r, c, d[N][N][N];
char mp[N][N][N];
queue<node> q;

int bfs(node st) {
    q.push(st);
    d[st.x][st.y][st.z] = 0;
    while (!q.empty()) {
        node t = q.front(); q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = t.x + dx[i], ny = t.y + dy[i], nz = t.z + dz[i];
            if (mp[nx][ny][nz] == '#') continue;
            if (d[nx][ny][nz] != 0x3f3f3f3f) continue;
            d[nx][ny][nz] = min(d[nx][ny][nz], d[t.x][t.y][t.z] + 1);
            if (mp[nx][ny][nz] == 'E')
                return d[nx][ny][nz];
            q.push({nx, ny, nz});
        }
    }
    return -1;
}

int main() {
    memset(d, 0x3f, sizeof d);
    memset(mp, '#', sizeof mp);
    cin >> l >> r >> c;
    node st;
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= r; j++) {
            scanf("%s", mp[i][j] + 1);
            for (int k = 1; k <= c; k++)
                if (mp[i][j][k] == 'S') {
                    st.x = i, st.y = j, st.z = k;
                    mp[i][j][k] = '#';
                }
        }
//    for (int i = 1; i <= l; i++, cout << endl)
//        for (int j = 1; j <= r; j++, cout << endl)
//            for (int k = 1; k <= c; k++)
//                cout << mp[i][j][k] << " ";
    int ans = bfs(st);
    if (ans == -1) cout << "Trapped!" << endl;
    else cout << ans << endl;
    return ans;
}
