#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, k; cin >> n >> k;
	map<int, vector<int>> mp; for(int i = 0; i < n; i++){ int a; cin >> a; mp[a%k].emplace_back(a); }

	int cnt = 0, ans = 0;
	for(auto& [a, v]: mp){
		sort(v.begin(), v.end());
		if(v.size()&1){
			cnt++;
			if(cnt > 1){ cout << "-1" << endl; return; }

			vector<vector<int>> dp(v.size(), vector<int>(3, LINF)); 
			dp[0][0] = LINF, dp[0][1] = 0; dp[0][2] = LINF;
			if(v.size() > 1) dp[1][0] = v[1]-v[0], dp[1][1] = LINF, dp[1][2] = LINF;
			for(int i = 2; i < v.size(); i++){
				dp[i][0] = dp[i-2][0]+v[i]-v[i-1];
				dp[i][1] = dp[i-1][0];
				dp[i][2] = min(dp[i-2][1], dp[i-2][2])+v[i]-v[i-1];
			}

			ans += min(dp.back()[1], dp.back()[2])/k;
		}
	}

	for(auto [a, b]: mp) if(!(b.size()&1)){
		for(int j = 1; j < b.size(); j += 2) ans += (b[j]-b[j-1])/k;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
