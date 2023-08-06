#include <bits/stdc++.h>
using namespace std;

int a[101], vis[101];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int k = 0;
        for (int j = 1; j <= m; j++)
            if (a[j] == i)
                k = j;
        if (k == 0) {
            if (!vis[i]) cout << i << " ";
            continue;
        }
        while (k < m && a[k + 1] == a[k] + 1)
            k++;
        for (int j = a[k] + 1; j >= i; j--)
            cout << j << " ", vis[j] = 1;
        i = a[k];
    }
    return 0;
}