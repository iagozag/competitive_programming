#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int dp[MAX][26]; 

void sum(int& a, int b){
	a %= MOD, b %= MOD;
	a += b, a %= MOD, a += MOD, a %= MOD;
}

void solve(){
	int n; cin >> n;
	memset(dp, 0, sizeof dp);

	int minus = 1; for(int i = 0; i < 26; i++) dp[1][i] = 1;
	for(int i = 2; i <= n; i++) for(int j = 0; j < 26; j++){
		for(int k = 0; k < 26; k++) sum(dp[i][j], dp[i-1][k]);

		if(j == 4 and i >= 16){
			sum(dp[i][j], -minus);
			minus *= 26, minus %= MOD;
		}
	}

	int ans = 0;
	for(int j = 0; j < 26; j++) sum(ans, dp[n][j]);
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
