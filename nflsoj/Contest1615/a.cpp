#include <bits/stdc++.h>
#define int long long
using namespace std;

int qpow(int a, int b, int p) {
    if (b == 0) return 1 % p;
    if (b == 1) return a % p;
    int tmp = qpow(a, b / 2, p) % p;
    if (b % 2) return tmp * tmp % p * a % p;
    else       return tmp * tmp % p;
}

class combMaths {
    private :
        unsigned n;
        int p;
        vector<int> fac;
        void getFactorial(unsigned L, unsigned R, int P) {
            if (n >= R) return;
            n = R;
            fac.resize(n + 1);
            fac[0] = 1;
            for (unsigned i = L; i <= R; i++)
                fac[i] = fac[i - 1] * i % P;
        }
    public :
        combMaths() {
        }
        combMaths(int P) {
            p = P;
        }
        int C(unsigned N, unsigned M, int P = 0) {
            if (P == 0) P = p;
            if (M > N) throw "M cannot be greater than N!";
            if (n < N) getFactorial(n + 1, N, P);
            return fac[N] * qpow(fac[M], P - 2 , P) % P * qpow(fac[N - M], P - 2, P) % P;
        }
        int A(unsigned N, unsigned M, int P = 0) {
            if (P == 0) P = p;
            if (M > N) throw "M cannot be greater than N!";
            if (n < N) getFactorial(n + 1, N, P);
            return C(N, M, P) * fac[M] % P;
        }
};

const int p = 998244353;
int t, n, m;
combMaths ie(p);

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        // n! C(n - 1, m - 1);
        cout << ie.A(n, n) * ie.C(n - 1, m - 1) % p << endl;
    }
    return 0;
}