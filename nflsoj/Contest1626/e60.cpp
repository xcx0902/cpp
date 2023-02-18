#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

int r, c, h, w, nowx = 1, nowy = 1, cnt, ans = 0x3f3f3f3f, a[1005][1005];
multiset<int> lft, rgt;
bool goingDir = 1; // 1 = rgt, 0 = lft
int vis[100005];

inline void movergt() {
    // cerr << "movergt" << endl;
    auto k = --lft.end();
    rgt.insert(*k);
    lft.erase(k);
}

inline void movelft() {
    // cerr << "movelft" << endl;
    auto k = rgt.begin();
    lft.insert(*k);
    rgt.erase(k);
}

inline void adjust() {
    // cerr << "Adjusting" << endl;
    if (lft.size() == 0 && rgt.size() == 0) return;
    if ((lft.size() + rgt.size()) % 2 == 0) return;
    while ((int)lft.size() - 1 != (int)rgt.size()) {
        // cerr << "Left: " << lft.size() << endl;
        // cerr << "Right: " << rgt.size() << endl;
        if ((int)lft.size() - 1 > (int)rgt.size()) movergt();
        else movelft();
    }
}

inline int getmid() {
    // cerr << "Getting mid" << endl;
    adjust();
    if (lft.empty()) return 0;
    else return *(--lft.end());
}

inline void ins(int x) {
    vis[x]++;
    // cerr << "Inserting " << x << endl;
    if (x > getmid()) rgt.insert(x);
    else lft.insert(x);
    adjust();
}

inline void del(int x) {
    vis[x]++;
    if (lft.find(x) != lft.end()) lft.erase(lft.find(x));
    else rgt.erase(rgt.find(x));
    adjust();
}

inline void nextcol() {
    if (goingDir) {
        for (int i = nowx; i <= nowx + h - 1; i++)
            del(a[i][nowy]);
        nowy++;
        for (int i = nowx; i <= nowx + h - 1; i++)
            ins(a[i][nowy + w - 1]);
    } else {
        for (int i = nowx; i <= nowx + h - 1; i++)
            del(a[i][nowy + w - 1]);
        nowy--;
        for (int i = nowx; i <= nowx + h - 1; i++)
            ins(a[i][nowy]);
    }
    adjust();
}

inline void nextline() {
    goingDir ^= 1;
    for (int i = nowy; i <= nowy + w - 1; i++)
        del(a[nowx][i]);
    nowx++;
    for (int i = nowy; i <= nowy + w - 1; i++)
        ins(a[nowx + h - 1][i]);
    adjust();
}

int main() {
    // freopen("e2.txt", "r", stdin);
    cin >> r >> c >> h >> w;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            ins(a[i][j]);
    ans = min(ans, getmid());
    while (1) {
        // cerr << nowx << " " << nowy << endl;
        // cerr << "lft: ";
        // for (int p: lft) cerr << p << " ";
        // cerr << endl;
        // cerr << "rgt: ";
        // for (int p: rgt) cerr << p << " ";
        // cerr << endl;
        if ((nowy == c - w + 1 && goingDir) || (nowy == 1 && !goingDir)) {
            if (nowx == r - h + 1) break;
            nextline();
        }
        else nextcol();
        ans = min(ans, getmid());
    }
    cout << ans << endl;
    // cout << cnt << endl;
    // for (int i = 1; i <= 25; i++)
    //     cerr << vis[i] << " ";
    return 0;
}