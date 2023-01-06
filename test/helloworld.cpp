#include <bits/stdc++.h>
using namespace std;

struct node {
    string s;
};

int main() {
    node* x;
    x = new node;
    x->s = "Hello World!";
    cout << x->s << endl;
    return 0;
}