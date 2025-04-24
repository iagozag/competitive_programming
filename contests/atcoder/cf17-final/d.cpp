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
	vector<pair<int, int>> v(n); for(auto& [a, b]: v) cin >> a >> b;
	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b){
		return a.first+a.second < b.first+b.second;
	});

	vector<vector<int>> dp(n+1, vector<int>(n+1, LINF)); dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		auto [hi, pi] = v[i-1];
		for(int j = n; j >= 0; j--){
			dp[i][j] = min(dp[i][j], dp[i-1][j]);

			if(dp[i][j] <= hi){
				dp[i][j+1] = min(dp[i][j+1], dp[i][j]+pi);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n+1; i++) for(int j = 0; j < n+1; j++) if(dp[i][j] != LINF) ans = max(ans, j);
	
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
