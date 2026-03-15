#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	int dp[n][3]; memset(dp, 0, sizeof dp);
	
	int qnt = 1;
	for(int i = 0; i < n; i++){
		if(i) for(int j = 0; j < 3; j++) dp[i][j] = dp[i-1][j];

		if(s[i] == 'a') dp[i][0] += qnt, dp[i][0] %= MOD;
		else if(s[i] == 'b') dp[i][1] += dp[i][0], dp[i][1] %= MOD;
		else if(s[i] == 'c') dp[i][2] += dp[i][1], dp[i][2] %= MOD;
		else{
			dp[i][2] = dp[i][2]*3+dp[i][1], dp[i][2] %= MOD;
			dp[i][1] = dp[i][1]*3+dp[i][0], dp[i][1] %= MOD;
			dp[i][0] = dp[i][0]*3+qnt, dp[i][0] %= MOD;

			qnt *= 3, qnt %= MOD;
		}
	}

	cout << dp[n-1][2]%MOD << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


