#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

void solve(){
	int n, k; cin >> n >> k;
	int dp[k+1][k+1]; memset(dp, 0, sizeof dp);

	dp[0][0] = 1;
	// dp(i, j) = i sorteios, j pessoas sorteadas
	for(int i = 1; i <= k; i++) for(int j = 1; j <= i; j++){
		dp[i][j] = ((dp[i-1][j]*j%MOD) + (dp[i-1][j-1]*(n-(j-1))%MOD))%MOD;
	}

	for(int i = 1; i <= k; i++) cout << dp[k][i] << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
