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
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();

	int dp[n+1][m+1];
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			dp[i][j] = LINF;

	dp[0][0] = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++) if(i or j){
			if(i) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
			if(j) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
			if(i and j) dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(s[i-1] != t[j-1]));
		}
	}

	cout << dp[n][m] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
