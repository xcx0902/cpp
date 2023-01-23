#include <bits/stdc++.h>
#define int long long
using namespace std;

/* -----Template Begin----- */

const int mod1 = 10007;
const int mod2 = 1e9 + 7;
const int mod3 = 998244353;

int mod;

class Matrix {
public:
    int n, m;
    vector<vector<int>> v;
    vector<int>& operator[](int x) { return v[x]; }
    void resize(int r, int c) {
        n = r, m = c;
        v = vector<vector<int>>(n, vector<int>(m));
    }
    void read() {
        cin >> n >> m;
        resize(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> v[i][j];
    }
    void print(bool printnm = false) {
        if (printnm)
            cout << n << " " << m << endl;
        for (int i = 0; i < n; i++, cout << endl)
            for (int j = 0; j < m; j++) cout << v[i][j] << " ";
    }
};

void useMod(int x) { mod = x; }

Matrix base(int n) {
    Matrix ret;
    ret.resize(n, n);
    for (int i = 0; i < n; i++) ret[i][i] = 1;
    return ret;
}

Matrix operator*(Matrix a, Matrix b) {
    if (a.m != b.n)
        throw "a.m != b.n";
    Matrix c;
    c.resize(a.n, b.m);
    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < b.m; j++)
            for (int k = 0; k < a.m; k++) (c[i][j] += a[i][k] * b[k][j]) %= mod;
    return c;
}

Matrix operator^(Matrix a, int b) {
    if (a.n != a.m)
        throw "a.n != a.m";
    if (b == 0)
        return base(a.n);
    if (b == 1)
        return a;
    Matrix tmp = a ^ (b >> 1);
    tmp = tmp * tmp;
    if (b & 1)
        tmp = tmp * a;
    return tmp;
}

/* -----Template Ended----- */

int n;
Matrix a, b;

signed main() {
    useMod(mod2);
    cin >> n;
    a.resize(1, 6), b.resize(6, 6);
    a[0] = { 1, 1, 8, 4, 2, 1 };
    b[0] = { 1, 1, 0, 0, 0, 0 };
    b[1] = { 1, 0, 0, 0, 0, 0 };
    b[2] = { 1, 0, 1, 0, 0, 0 };
    b[3] = { 3, 0, 3, 1, 0, 0 };
    b[4] = { 3, 0, 3, 2, 1, 0 };
    b[5] = { 2, 0, 1, 1, 1, 1 };
    if (n <= 2)
        cout << 1 << endl;
    else
        cout << (a * (b ^ (n - 2)))[0][0] << endl;
    return 0;
}