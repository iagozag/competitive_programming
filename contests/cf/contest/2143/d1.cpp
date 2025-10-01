#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void sum(int& a, int b){
	a += b, a %= MOD;
}

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;

	int dp[n][n+1][n+1]; memset(dp, 0, sizeof dp);

	for(int i = 0; i < n; i++){
		sum(dp[i][1][v[i]], 1);
		for(int j = 2; j <= n; j++)
			for(int k = v[i]+1; k <= n; k++){
				sum(dp[i][j][v[i]], dp[i-1][j-1][k]);
			}
	}

	int tot = 1;
	for(int i = 0; i < n; i++) tot = tot*2%MOD;

	for(int i = 0; i < n; i++) for(int j = 3; j <= n; j++) for(int k = 0; k <= n; k++)
		sum(tot, dp[i][j][k]);
	cout << tot+1 << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
