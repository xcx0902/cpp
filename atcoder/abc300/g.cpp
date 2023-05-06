#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> u = {1}, v = {1};
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int n, p, ans;

void add(vector<int> &a, int p) {
    int sz = a.size();
    for (int i = 0; i < sz; i++) {
        int tmp = a[i];
        while (tmp * p <= n) {
            tmp *= p;
            a.push_back(tmp);
        }
    }
}

signed main() {
    cin >> n >> p;
    while (p < prime.back()) prime.pop_back();
    for (int x: prime) {
        if (u.size() < v.size()) add(u, x);
        else add(v, x);
    }
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    for (int i = 0, j = v.size() - 1; i < u.size(); i++) {
        while (j >= 0 && v[j] * u[i] > n) j--;
        if (j < 0) break;
        ans += j + 1;
    }
    cout << ans << endl;
    return 0;
}