#include <bits/stdc++.h>
#define int long long
using namespace std;

#ifdef __MOD
int qpow(int a, int b, int p = __mod)
#else
int qpow(int a, int b, int p)
#endif
{   if (b == 0) return 1 % p;
    if (b == 1) return a % p;
    int tmp = qpow(a, b / 2, p) % p;
    if (b % 2) return tmp * tmp % p * a % p;
    else       return tmp * tmp % p;
}

/* ----- CombMaths Begin ----- */
class combMaths {
    private :
        unsigned n;
        int p;
        std::vector<int> fac;
        void getFactorial(unsigned L, unsigned R, int P) {
            if (n >= R) return;
            n = R;
            fac.resize(n + 1);
            fac[0] = 1;
            for (unsigned i = L; i <= R; i++)
                fac[i] = fac[i - 1] * i % P;
        }

    public :
        combMaths() { }
        combMaths(int P) { p = P; }

        void resetMod(int P) {
            p = P, n = 0;
            fac.clear();
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

#ifndef __DO_NOT_CREATE_COMBMATHS_CLASS

#ifdef __MOD
combMaths __cm(__mod);
#else
combMaths __cm(1e9 + 7);
#endif // __MOD

#define C(__N, __M) __cm.C(__N, __M)
#define A(__N, __M) __cm.A(__N, __M)

#endif // __DO_NOT_CREATE_COMBMATHS_CLASS
/* ------ CombMaths End ------ */

const int mod = 1e9 + 7;

int n, k, ans;

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        ans += C(n - 1, i - 1) * A(k, i) % mod;
    cout << ans << endl;
    return 0;
}
