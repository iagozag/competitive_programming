#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 16, MOD = 1e9+7;

int dp[1<<MAX][MAX][MAX];

void solve(){
	int n, m; cin >> n >> m;
	int mat[n][m], mi[n][n], mi2[n][n];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> mat[i][j];

	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) mi[i][j] = mi2[i][j] = LINF;

	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
		for(int k = 0; k < m; k++){
			mi[i][j] = min(mi[i][j], abs(mat[i][k]-mat[j][k]));
			if(k+1 < m) mi2[i][j] = min(mi2[i][j], abs(mat[i][k]-mat[j][k+1]));
		}
	}

	// 1<<n mask, begin in i, finish in j
	for(int i = 0; i < (1<<n); i++) for(int j = 0; j < n; j++) for(int k = 0; k < n; k++) dp[i][j][k] = 0;

	for(int i = 1; i < (1<<n); i++){
		if(__builtin_popcount(i) == 1){
			int bit = __builtin_ctz(i);
			dp[i][bit][bit] = LINF;
		}

		for(int l = 0; l < n; l++) // begin
			for(int j = 0; j < n; j++) if((i>>j)&1){ // finish
				for(int k = 0; k < n; k++) if(!((i>>k)&1)){ // adding
						dp[i|(1<<k)][l][k] = max(dp[i|(1<<k)][l][k], min(dp[i][l][j], mi[j][k]));
				}
			}
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans = max(ans, min(dp[(1<<n)-1][i][j], mi2[j][i]));
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
