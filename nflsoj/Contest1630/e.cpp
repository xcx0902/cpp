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
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int P = 10000, N = 205;
int n, m, a[N][N];

struct Int {
    int num[25], len;
    Int() { memset(num, 0, sizeof num), len = 0; }
    void print() {
        printf("%d", num[len]);  
        for (int i = len - 1; i > 0; i--) {  
            if (num[i] == 0) {
                printf("0000"); 
                continue;
            }
            for (int k = 10; k * num[i] < P; k *= 10) 
                printf("0");
            printf("%d", num[i]);
        }
    }
} f[N][N], pow2[N], ans;

Int operator+(const Int &a, const Int &b) {
    Int c;
    int x = 0;
    c.len = max(a.len, b.len);
    for (int i = 1; i <= c.len; i++) {
        c.num[i] = a.num[i] + b.num[i] + x;
        x = c.num[i] / P;
        c.num[i] %= P;
    }
    if (x > 0) c.num[++c.len] = x;
    return c;
}

Int operator*(const Int &a, const int &b) {
    Int c;
    int x = 0;
    c.len = a.len;
    for (int i = 1; i <= c.len; i++) {
        c.num[i] = a.num[i] * b + x;
        x = c.num[i] / P;
        c.num[i] %= P;
    }
    while (x > 0) c.num[++c.len] = x % P, x /= P;
    return c;
}

Int max(const Int &a, const Int &b) {
    if (a.len > b.len) return a;
    else if (a.len < b.len) return b;
    for (int i = a.len; i > 0; i--)
        if (a.num[i] > b.num[i]) return a;
        else if (a.num[i] < b.num[i]) return b;
    return a;
}

void init() {
    pow2[0].num[1] = 1, pow2[0].len = 1;
    for (int i = 1; i <= m + 2; i++)
        pow2[i] = pow2[i - 1] * 2;
}

signed main() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++) {
        memset(f, 0, sizeof(f));
        for (int j = 1; j <= m; j++)
            for (int k = m; k >= j; k--) {
                f[j][k] = max(f[j][k], f[j - 1][k] + pow2[m - k + j - 1] * a[i][j - 1]); 
                f[j][k] = max(f[j][k], f[j][k + 1] + pow2[m - k + j - 1] * a[i][k + 1]);
            }
        Int tmp;
        for (int j = 1; j <= m; j++)
            tmp = max(tmp, f[j][j] + pow2[m] * a[i][j]);
        ans = ans + tmp;
    }
    ans.print();
    return 0;
}