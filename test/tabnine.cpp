#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        ll ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                ans++;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
