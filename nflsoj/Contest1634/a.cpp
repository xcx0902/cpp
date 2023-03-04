#include <bits/stdc++.h>
using namespace std;

int a, b, x[10], y[10];

void resolve(int n, int p[]) {
    while (n) {
        p[++p[0]] = n % 10;
        n /= 10;
    }
}

void mkmin(int p[]) {
    for (int i = 1; i <= p[0]; i++)
        if (p[i] == 6)
            p[i] = 5;
}

void mkmax(int p[]) {
    for (int i = 1; i <= p[0]; i++)
        if (p[i] == 5)
            p[i] = 6;
}

void merge(int p[], int &n) {
    n = 0;
    for (int i = p[0]; i >= 1; i--)
        n = n * 10 + p[i];
}

int main() {
    cin >> a >> b;
    resolve(a, x);
    resolve(b, y);
    mkmin(x);
    mkmin(y);
    merge(x, a);
    merge(y, b);
    cout << a + b << " ";
    mkmax(x);
    mkmax(y);
    merge(x, a);
    merge(y, b);
    cout << a + b << endl;
    return 0;
}
