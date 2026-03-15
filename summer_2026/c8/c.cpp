#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;
typedef long double ld;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<ld>> mat(n, vector<ld>(n));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> mat[i][j];

	vector<vector<ld>> dp(m+1, vector<ld>(n)); dp[0][0] = 1.0;
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			for(int k = 0; k < n; k++) dp[j+1][k] += dp[j][i]*mat[i][k];
		}
	}

	for(int i = 0; i < n; i++) cout << fixed << setprecision(9) << dp[m][i] << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}
