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
	int n, q; cin >> n >> q;
	vector<int> v(n); for(auto& x: v) cin >> x, --x;

	vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(31));
	for(int i = 0; i < n; i++) dp[i][0] = {i+1, v[i]};
	for(int j = 1; j < 31; j++){
		for(int i = 0; i < n; i++){
			auto [a, b] = dp[i][j-1];
			auto [c, d] = dp[b][j-1];
			dp[i][j] = {a+c, d};
		}
	}

	for(int i = 0; i < q; i++){
		int t, b; cin >> t >> b; --b;

		int ans = 0;
		for(int j = 0; j < 31; j++) if(t&(1<<j)){
			ans += dp[b][j].first, b = dp[b][j].second;
		}

		cout << ans << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
