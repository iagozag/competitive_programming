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
	vector<string> v(n);
	for(auto& x: v) cin >> x;

	vector<vector<int>> dp(n, vector<int>(n, LINF)); dp[0][0] = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(i < n-1 or j < n-1){
		if(i == n-1) dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
		else if(j == n-1) dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
		else{
			if(v[i+1][j] > v[i][j+1]) dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
			else if(v[i+1][j] < v[i][j+1]) dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
			else dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1), dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
		}
	}


	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cout << dp[i][j] << " \n"[j==n-1];
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
