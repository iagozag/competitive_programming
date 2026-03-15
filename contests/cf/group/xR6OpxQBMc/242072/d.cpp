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
	string s = " ilarilariegegege"; int m = s.size()-1;

	vector<vector<int>> dp(n+1, vector<int>(m));
	dp[0][0] = 25, dp[0][1] = 1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int c = 'a'; c <= 'z'; c++){
				if(s[j+1] == c){
					if(j < m-1) dp[i+1][j+1] += dp[i][j], dp[i+1][j+1] %= MOD;
					continue;
				}
				if(c == 'i') dp[i+1][1] += dp[i][j], dp[i+1][1] %= MOD;
				else{
					if(j == 9 and c == 'l') dp[i+1][6] += dp[i][j], dp[i+1][6] %= MOD;
					else dp[i+1][0] += dp[i][j], dp[i+1][0] %= MOD;
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < m; i++) ans += dp[n-1][i], ans %= MOD;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
