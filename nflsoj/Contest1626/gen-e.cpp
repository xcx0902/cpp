#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt = 0;
    freopen("e2.txt", "w", stdout);
    cout << "300 300 151 151" << endl;
    for (int i = 1; i <= 300; i++, cout << endl)
        for (int j = 1; j <= 300; j++)
            cout << ++cnt << " ";
    return 0;
}
