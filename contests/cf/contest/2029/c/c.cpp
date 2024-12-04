#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n; vector<int> v(n); for(auto& x: v) cin >> x;
	vector<vector<int>> dp(n, vector<int>(3)); dp[0] = {1, 0, -INF};
	for(int i = 1; i < n; i++){
		dp[i][0] = dp[i-1][0];
		if(v[i] != dp[i][0]) dp[i][0] += v[i] > dp[i][0] ? 1 : -1;
		dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
		dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
		if(v[i] != dp[i][2]) dp[i][2] += v[i] > dp[i][2] ? 1 : -1;
	}
	cout << max(dp[n-1][1], dp[n-1][2]) << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

