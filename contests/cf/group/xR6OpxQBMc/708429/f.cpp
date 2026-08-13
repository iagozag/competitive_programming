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
	vector<tuple<int, int, int>> v(n); for(auto& [a, b, c]: v) cin >> a >> b >> c;
	sort(v.begin(), v.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b){
		auto [w1, s1, h1] = a;
		auto [w2, s2, h2] = b;

		return s1-w2 > s2-w1;
	});

	int dp[1001][1500]; memset(dp, 0, sizeof dp);
	for(int i = 1; i <= n; i++){
		auto [w, s, h] = v[i-1];

		for(int j = w; j < 1500; j++){
			dp[i][min(j-w, s)] = max(dp[i][min(j-w, s)], dp[i-1][j]+h);
		}

		for(int j = 0; j < 1500; j++) 
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
	}

	int ans = 0;
	for(int i = 0; i < 1500; i++) ans = max(ans, dp[n][i]);
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

