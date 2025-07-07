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
	int n; cin >> n;
	vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];

	map<int, int> mp; vector<int> dp(n, INF); dp[0] = 1; mp[v[0]] = 1;
	for(int i = 1; i < n; i++){
		dp[i] = dp[i-1]+1;
		if(mp.count(v[i])) dp[i] = min(dp[i], mp[v[i]]), mp[v[i]] = min(dp[i], mp[v[i]]);
		else mp[v[i]] = dp[i];
	}

	cout << dp.back() << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
