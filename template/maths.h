#include <vector>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
#define int long long

#ifdef __MOD
int __mod;

void setMod(int x) {
    __mod = x;
}
#endif // __MOD

inline void add(int &x, int y) {
    #ifdef __MOD
    x = (x + y) % __mod;
    #else
    x = x + y;
    #endif // __MOD
}

inline void sub(int &x, int y) {
    #ifdef __MOD
    x = (x + __mod - y) % __mod;
    #else
    x = x - y;
    #endif // __MOD
}

#undef gcd
#undef lcm
#undef lowbit
#undef ctz
#undef ctzll
#undef popcount

#define gcd(__a, __b) __gcd(__a, __b)
#define lcm(__a, __b) __lcm(__a, __b)

#define lowbit(__x) ((__x) & (-(__x)))
#define ctz(__x) __builtin_ctz(__x)
#define ctzll(__x) __builtin_ctzll(__x)
#define popcount(__x) __builtin_popcount(__x)

#ifdef __MOD
int qpow(int a, int b, int p = __mod) {
#else
int qpow(int a, int b, int p) {
#endif
    if (b == 0) return 1 % p;
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
combMaths __cm(LONG_LONG_MAX);
#endif // __MOD

#define C(__N, __M) __cm.C(__N, __M)
#define A(__N, __M) __cm.A(__N, __M)

#endif // __DO_NOT_CREATE_COMBMATHS_CLASS
/* ------ CombMaths End ------ */

int binarySearch(int l, int r, bool (*check)(int), int ans = 0) {
    int mid = 0;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    return ans;
}

double binarySearch(double l, double r, bool (*check)(double), double eps = 1e-6, double ans = 0) {
    double mid = 0;
    while (abs(l - r) > eps) {
        mid = (l + r) / 2;
        if (check(mid)) l = mid, ans = mid;
        else r = mid;
    }
    return ans;
}

int getDivisor(int a[], int n, int cnt = 1) {
    int tmp = cnt;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            a[cnt++] = i;
            if (i * i != n)
                a[cnt++] = n / i;
        }
    cnt--;
    std::sort(a + tmp, a + cnt + 1);
    return cnt;
}

int getDivisor(std::vector<int> &v, int n) {
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            v.push_back(i);
            if (i * i != n)
                v.push_back(n / i);
        }
    std::sort(v.begin(), v.end());
    return v.size();
}

std::vector<int> getDivisor(int n) {
    std::vector<int> ret;
    for (int i = 1; i  * i <= n; i++)
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    std::sort(ret.begin(), ret.end());
    return ret;
}

#undef int