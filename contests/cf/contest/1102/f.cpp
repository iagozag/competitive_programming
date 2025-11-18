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
	int mat[n][m], mi[n][n];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> mat[i][j];

	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
		mi[i][j] = LINF;
		for(int k = 0; k < m; k++) mi[i][j] = min(mi[i][j], abs(mat[i][k]-mat[j][k]));
	}

	// 1<<n mask, begin in i, finish in j
	int dp[1<<n][n][n]; memset(dp, 0, sizeof dp);

	for(int i = 1; i < (1<<n); i++){
		for(int j = 0; j < n; j++) if((i>>j)&1){
			for(int k = 0; k < n; k++) if(!((i>>k)&1)){
				dp[i|(1<<k)][k] = max(dp[i|(1<<k)][k], mi[j][k]);
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, dp[(1<<n)-1][i]);
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
