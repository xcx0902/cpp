#include <vector>
#include <iostream>
#include <limits>
#define int long long

const int mod1 = 10007;
const int mod2 = 1e9 + 7;
const int mod3 = 998244353;

int mod = LONG_LONG_MAX;

class Matrix {
public:
    int n, m;
    std::vector<std::vector<int>> v;
    std::vector<int>& operator[](int x) {
        return v[x];
    }
    void resize(int r, int c) {
        n = r, m = c;
        v = std::vector<std::vector<int>>(n, std::vector<int>(m));
    }
    void read() {
        std::cin >> n >> m;
        resize(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                std::cin >> v[i][j];
    }
    void print(bool printnm = false) {
        if (printnm)
            std::cout << n << " " << m << std::endl;
        for (int i = 0; i < n; i++, std::cout << std::endl)
            for (int j = 0; j < m; j++)
                std::cout << v[i][j] << " ";
    }
};

int mul(int a, int b) {
    int ans = 0;
    while (b) {
        if (b & 1)
            ans = (ans + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return ans;
}

void useMod(int x) { mod = x; }

Matrix base(int n) {
    Matrix ret;
    ret.resize(n, n);
    for (int i = 0; i < n; i++)
        ret[i][i] = 1;
    return ret;
}

Matrix operator*(Matrix a, Matrix b) {
    if (a.m != b.n)
        throw "a.m != b.n";
    Matrix c;
    c.resize(a.n, b.m);
    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < b.m; j++)
            for (int k = 0; k < a.m; k++)
                (c[i][j] += mul(a[i][k], b[k][j])) %= mod;
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

#undef int