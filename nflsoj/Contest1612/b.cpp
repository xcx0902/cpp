#include <bits/stdc++.h>
using namespace std;

int n;
string s;
map<char, char> mp;
pair<string, string> a[10001];

int main() {
	cin >> n >> s;
	for (int i = 0; i < 26; i++)
		mp[s[i]] = i + 'a';
	for (int i = 1; i <= n; i++)
		cin >> a[i].first, a[i].second = a[i].first;
	for (int i = 1; i <= n; i++)
		for (char &c: a[i].first)
			c = mp[c];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		cout << a[i].second << endl;
	return 0;
}