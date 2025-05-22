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
	string mat[n];
	for(int i = 0; i < n; i++) cin >> mat[i];

	int dp[n][n]; memset(dp, 0, sizeof dp); dp[0][0] = mat[0][0] == '.';
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(mat[i][j] == '.'){
		if(i-1 >= 0) dp[i][j] += dp[i-1][j], dp[i][j] %= MOD;
		if(j-1 >= 0) dp[i][j] += dp[i][j-1], dp[i][j] %= MOD;
	}

	cout << dp[n-1][n-1] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
