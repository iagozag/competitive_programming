#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	int mat[n][3];
	for(int i = 0; i < n; i++) for(int j = 0; j < 3; j++) cin >> mat[i][j];

	int dp[n][3]; memset(dp, 0, sizeof dp);
	dp[0][0] = mat[0][0], dp[0][1] = mat[0][1], dp[0][2] = mat[0][2];
	for(int i = 1; i < n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++) if(k != j) dp[i][k] = max(dp[i][k], dp[i-1][j]+mat[i][k]);
		}
	}

	cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}
