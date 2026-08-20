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
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

	vector<vector<int>> dp(n, vector<int>(m+1)), dp2(n, vector<int>(m+1));
	for(int i = 0; i < n; i++) for(int j = 0; j <= m; j++){
		if(i) dp[i][j] = max(dp[i][j], dp[i-1][j]);
		if(j >= v[i].first) dp[i][j] = max(dp[i][j], (i ? dp[i-1][j-v[i].first] : 0)+v[i].second);
	}

	for(int i = n-1; i >= 0; i--) for(int j = 0; j <= m; j++){
		if(i < n-1) dp2[i][j] = max(dp2[i][j], dp2[i+1][j]);
		if(j >= v[i].first) dp2[i][j] = max(dp2[i][j], (i+1 < n ? dp2[i+1][j-v[i].first] : 0)+v[i].second);
	}
	
	int ma = 0;
	for(int j = 0; j <= m; j++) ma = max(ma, dp[n-1][j]);

	for(int i = 0; i < n; i++){
		int a = 0, c = 0;
		for(int j = 0; j <= m; j++){
			if(m-j-v[i].first >= 0) a |= ((i ? dp[i-1][j] : 0) + (i+1 < n ? dp2[i+1][m-j-v[i].first] : 0)) == ma-v[i].second;
			if(m-j >= 0) c |= ((i ? dp[i-1][j] : 0) + (i+1 < n ? dp2[i+1][m-j] : 0)) == ma;
		}

		if(a and c) cout << 'B';
		else if(a) cout << 'A';
		else cout << 'C';
	}
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
