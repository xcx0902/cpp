#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000005;
int n, mx, mn, a[N], lmx[N], rmx[N], lmn[N], rmn[N];
stack<int> s;

void getlmx() {
	a[0] = 1145141919810LL;
	s = stack<int>();
	for (int i = 0; i <= n; i++) {
        while (!s.empty() && a[s.top()] <= a[i])
        	s.pop();
        lmx[i] = i - (s.empty()? 0 : s.top());
        s.push(i);
    }
}

void getrmx() {
	a[n + 1] = 1145141919810LL;
	s = stack<int>();
	for (int i = n + 1; i >= 1; i--) {
        while (!s.empty() && a[s.top()] < a[i])
        	s.pop();
        rmx[i] = (s.empty()? 0 : s.top()) - i;
        s.push(i);
    }
}

void getlmn() {
	a[0] = -1145141919810LL;
	s = stack<int>();
	for (int i = 0; i <= n; i++) {
        while (!s.empty() && a[s.top()] >= a[i])
        	s.pop();
        lmn[i] = i - (s.empty()? 0 : s.top());
        s.push(i);
    }
}

void getrmn() {
	a[n + 1] = -1145141919810LL;
	s = stack<int>();
	for (int i = n + 1; i >= 1; i--) {
        while (!s.empty() && a[s.top()] > a[i])
        	s.pop();
        rmn[i] = (s.empty()? 0 : s.top()) - i;
        s.push(i);
    }
}

void dbg(int a[], string msg = "Debugging") {
	cout << msg << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	getlmx(), getrmx();
	getlmn(), getrmn();
//	dbg(lmx), dbg(rmx);
//	dbg(lmn), dbg(rmn);
	for (int i = 1; i <= n; i++)
		mx += a[i] * lmx[i] * rmx[i], mn += a[i] * lmn[i] * rmn[i];
	cout << mn << endl;
	return 0;
}