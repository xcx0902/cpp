#include <bits/stdc++.h>
using namespace std;

int n, t, p, score[2005];
bool a[2005][2005];
struct node {
    int score, solved, id;
    bool operator < (node b) const {
        if (score != b.score) return score > b.score;
        if (solved != b.solved) return solved > b.solved;
        return id < b.id;
    }
} players[2005];

int main() {
    cin >> n >> t >> p;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= t; j++)
            cin >> a[i][j];
    for (int i = 1; i <= t; i++)
        for (int j = 1; j <= n; j++)
            if (a[j][i] == 0)
                score[i]++;
    for (int i = 1; i <= n; i++)
        players[i].id = i;
    for (int i = 1; i <= n; i++) {
        int slv = 0, scr = 0;
        for (int j = 1; j <= t; j++)
            if (a[i][j] == 1)
                slv++, scr += score[j];
        players[i].score = scr;
        players[i].solved = slv;
    }
    cout << players[p].score << " ";
    sort(players + 1, players + n + 1);
    for (int i = 1; i <= n; i++)
        if (players[i].id == p)
            cout << i << endl;
    return 0;
}
