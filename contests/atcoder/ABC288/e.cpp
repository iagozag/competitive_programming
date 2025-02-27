#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5e3+10, MOD = 1e9+7;

int n, m;
vector<int> a, b, c;

void solve(){
	cin >> n >> m;
	a = b = vector<int>(n), c = vector<int>(MAX);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;
	for(int i = 0; i < m; i++){ int x; cin >> x; c[x-1] = 1; }

	vector<vector<int>> cost(n, vector<int>(n, LINF));
	for(int i = 0; i < n; i++) cost[i][0] = b[i];
	for(int i = 1; i < n; i++) for(int j = 1; j <= i; j++) cost[i][j] = min(cost[i][j-1], b[i-j]);

	vector<vector<int>> dp(n+1, vector<int>(n+1, LINF)); dp[0][0] = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j <= i; j++){
		dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+a[i]+cost[i][j]);
		if(!c[i]) dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
	}

	int ans = LINF;
	for(int j = 0; j <= n; j++) ans = min(ans, dp[n][j]);
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
