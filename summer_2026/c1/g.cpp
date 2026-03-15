#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
	int n; cin >> n;
	vector<pair<int, int>> v(n+1);
	for(auto& [a, b]: v) cin >> a >> b;
	v.emplace_back(0, 0);
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	vector<vector<int>> dp(n+10, vector<int>(n+10, -LINF));
	dp[0][0] = v[0].second;
	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < n+1; j++){
			int remain = dp[i][j]-(v[i].first-v[i+1].first);
			if(remain < 0) continue;

			dp[i+1][j] = max(dp[i+1][j], remain);
			dp[i+1][j+1] = max(dp[i+1][j+1], remain+v[i+1].second);
		}
	}

	int ans = -1;
	for(int i = 0; i < n+1; i++) if(dp[n+1][i] >= 0){
		ans = i; break;
	}

	cout << ans << endl;
}

int32_t main(){
	int ttt; cin >> ttt;
	while(ttt--) solve();
	exit(0);
}
