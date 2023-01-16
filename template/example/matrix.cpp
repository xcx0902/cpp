#include <bits/stdc++.h>
#include "../matrix.h"
using namespace std;

Matrix a, b;

int main() {
    cout << "Input matrix a:" << endl;
    a.read();
    cout << "Input matrix b:" << endl;
    b.read();
    cout << "a * b =" << endl;
    (a * b).print(1);
    return 0;
}