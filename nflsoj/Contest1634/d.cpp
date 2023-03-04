#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, m, k, belong[N], vis[N];
vector<int> fac[N];
char op;

void resolve(int n) {
    int ori = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            fac[ori].push_back(i);
        }
    }
    if (n > 1) fac[ori].push_back(n);
}

int check(int now) {
    for (int i = 0; i < fac[now].size(); i++)
        if (belong[fac[now][i]])
            return belong[fac[now][i]];
    return 0;
}

void insert(int now) {
    for (int i = 0; i < fac[now].size(); i++)
        belong[fac[now][i]] = now;
}

void remove(int now) {
    for (int i = 0; i < fac[now].size(); i++)
        belong[fac[now][i]] = 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        resolve(i);
    for (int i = 1; i <= m; i++) {
        cin >> op >> k;
        if (op == '+') {
            if (vis[k]) cout << "Already on" << endl;
            else {
                if (check(k)) cout << "Conflict with " << check(k) << endl;
                else vis[k] = 1, insert(k), cout << "Success" << endl;
            }
        } else {
            if (!vis[k]) cout << "Already off" << endl;
            else vis[k] = 0, remove(k), cout << "Success" << endl;
        }
    }
    return 0;
}