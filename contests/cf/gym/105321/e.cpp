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
	int n, p; cin >> n >> p;
	vector<tuple<int, int, int>> v(n);
	for(auto& [a, b, c]: v) cin >> a >> b >> c;

	sort(v.begin(), v.end(), [&](tuple<int, int, int> x, tuple<int, int, int> y){
		auto [a1, b1, c1] = x;
		auto [a2, b2, c2] = y;
		
		return b2*(1-a1) > b1*(1-a2);
	});

	 vector<vector<int>> dp(n+1, vector<int>(p+1));
	 for(int i = 0; i < n; i++){
		 auto [a, b, c] = v[i];
		for(int j = p; j >= 0; j--){
			if(j < p) dp[i][j] = max(dp[i][j], dp[i][j+1]);

			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

			int idx = (j-b)/a;
			if(j-b >= 0) dp[i+1][idx] = max(dp[i+1][idx], dp[i][j]+c);
		}
	 }

	int ans = 0;
	for(int i = 0; i <= p; i++) ans = max(ans, dp[n][i]);

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
