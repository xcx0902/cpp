#include <bits/stdc++.h>
//#define dbg cerr << "Line " << __LINE__ << endl
#define dbg
#warning
using namespace std;

string s;
stack<pair<char, int>> st;
char c;
int l, r, ans;

int main() {
	cin >> s;
	dbg;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') st.push({s[i], i});
		else {
			if (!st.empty() && st.top().first == '(') st.pop();
			else st.push({s[i], i});
		}
	}
	dbg;
	if (st.empty()) {
		cout << 0 << endl;
		return 0;
	}
	c = st.top().first;
	r = st.top().second;
	st.pop();
	l = st.top().second;
	dbg;
	if (c == '(') {
		for (int i = r; i < s.size(); i++)
			ans += s[i] == c;
		cout << ans << endl;
	} else {
		for (int i = l; i >= 0; i--)
			ans += s[i] == c;
		cout << ans << endl;
	}
	return 0; 
}