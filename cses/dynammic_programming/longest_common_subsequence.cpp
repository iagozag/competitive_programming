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
	vector<int> v(n), w(m);
	for(auto& x: v) cin >> x;
	for(auto& x: w) cin >> x;

	int dp[n+1][m+1];
	memset(dp, 0, sizeof dp);
	for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++){
		if(i) dp[i][j] = max(dp[i-1][j], dp[i][j]);
		if(j) dp[i][j] = max(dp[i][j-1], dp[i][j]);
		if(i and j) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+(v[i-1] == w[j-1]));
	}

	vector<int> ans; int i = n, j = m;
	while(i and j){
		int a = i, b = j;
		if(dp[i-1][j] > dp[i][j-1]) a = i-1;
		else b = j-1;

		if(dp[i-1][j-1]+(v[i-1] == w[j-1]) > dp[a][b]){
			ans.emplace_back(v[i-1]);
			a = i-1, b = j-1;
		}

		i = a, j = b;
	}
	
	cout << dp[n][m] << endl;
	reverse(ans.begin(), ans.end());
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
