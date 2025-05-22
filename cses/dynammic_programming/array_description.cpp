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
	int n, m; cin >> n >> m;
	vector<int> v(n); for(auto& x: v) cin >> x;
	vector<vector<int>> dp(n, vector<int>(m+1));

	if(v[0] == 0) for(int i = 1; i <= m; i++) dp[0][i] = 1;
	else dp[0][v[0]] = 1;

	for(int i = 1; i < n; i++){
		if(v[i] == 0){
			for(int j = 1; j <= m; j++){
				if(j > 1) dp[i][j] += dp[i-1][j-1], dp[i][j] %= MOD;
				dp[i][j] += dp[i-1][j], dp[i][j] %= MOD;
				if(j+1 <= m) dp[i][j] += dp[i-1][j+1], dp[i][j] %= MOD;
			}
		} else{
			if(v[i] > 1) dp[i][v[i]] += dp[i-1][v[i]-1], dp[i][v[i]] %= MOD;
			dp[i][v[i]] += dp[i-1][v[i]], dp[i][v[i]] %= MOD;
			if(v[i]+1 <= m) dp[i][v[i]] += dp[i-1][v[i]+1], dp[i][v[i]] %= MOD;
		}
	}

	int ans = 0;
	for(int i = 1; i <= m; i++) ans += dp[n-1][i], ans %= MOD;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
