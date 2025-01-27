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
	vector<int> v(n); vector<vector<int>> dp(n, vector<int>(n)); for(auto& x: v) cin >> x;
	for(int i = 0; i < n; i++){
		for(int j = 1; j < n; j++){
			if(i-j >= 0) dp[i][j] = (v[i-j] == v[i] ? dp[i-j][j]+1 : 0);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) for(int j = 1; j < n; j++) ans = max(ans, dp[i][j]);
	cout << ans+1 << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
