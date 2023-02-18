#include <bits/stdc++.h>
using namespace std;

int h, m, lst = 7200;

int main() {
    scanf("%02d:%02d", &h, &m);
    while (1) {
        m++;
        if (m == 60) m = 0, h++;
        if (h == 24) h = 0;
        if ((h > 7 || h == 7 && m > 0) && h < 10 ||
            (h > 15 || h == 15 && m > 0) && h < 19) lst -= 30;
        else lst -= 60;
        if (lst < 30) break;
    }
    printf("%02d:%02d\n", h, m);
    return 0;
}
