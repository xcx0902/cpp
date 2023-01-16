#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void down(int vk) {
	keybd_event(vk, 0, 0, 0);
}

void up(int vk) {
	keybd_event(vk, 0, KEYEVENTF_KEYUP, 0);
}

void press(int vk) {
	down(vk);
	up(vk);
}

int main() {
	Sleep(3000);
    while (1) {
        int r = rand() % 15;
        if (r >= 0 && r <= 3) press(VK_UP), cout << "Press UP" << endl; 
        else if (r >= 4 && r <= 7) press(VK_DOWN), cout << "Press DOWN" << endl;
        else if (r >= 8 && r <= 11) press(VK_LEFT), cout << "Press LEFT" << endl;
        else if (r >= 11 && r <= 14) press(VK_RIGHT), cout << "Press RIGHT" << endl;
		Sleep(30);
    }
	return 0;
}
