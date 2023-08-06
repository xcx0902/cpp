#include <bits/stdc++.h>
using namespace std;

int tot, p[300000005];

int main() {
    while (1) {
        if (tot == 300000000) tot = 0;
        p[++tot] = tot;
    }
    return 0;
}