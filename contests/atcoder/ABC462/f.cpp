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
	string s; cin >> s; s = " "+s;
	int n = s.size(), k; cin >> k;

	vector<int> z(n), x(n);
	for(int i = 3; i < n; i++) 
		z[i] = (s[i-2] == 'A' and s[i-1] == 'B' and s[i] == 'C'), x[i] = z[i-2]+z[i-1]+z[i];

	vector<vector<int>> dp(n+1, vector<int>(k+1, INF));
	dp[0][0] = 0;
	for(int i = 0; i < n; i++){
		int diff = 0;
		if(i < n-3) diff = (s[i+1] != 'A') + (s[i+2] != 'B') + (s[i+3] != 'C');

		for(int j = 0; j <= k; j++){
			if(i+3 < n and j+1-x[i+3] <= k) dp[i+3][j+1-x[i+3]] = min(dp[i+3][j+1-x[i+3]], dp[i][j]+diff);
			if(i+1 < n and j-z[i+1] >= 0) dp[i+1][j-z[i+1]] = min(dp[i+1][j-z[i+1]], dp[i][j]);
		}
	}


	cout << (dp[n-1][k] >= INF ? -1 : dp[n-1][k]) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
