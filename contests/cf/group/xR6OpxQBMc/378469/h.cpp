#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, sum = 0; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x, sum += x;
	for(int i = 0; i < n; i++) v.emplace_back(v[i]);

	int mean = sum/n;
	for(auto& x: v) x -= mean;

	vector<int> pref(2*n); pref[0] = v[0];
	for(int i = 1; i < 2*n; i++) pref[i] = pref[i-1]+v[i];

	map<int, int> mp; int ans = 0;
	for(int i = 0; i < n; i++){
		mp[pref[i]]++;
		ans = max(ans, mp[pref[i]]);
	}

	cout << n-ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
