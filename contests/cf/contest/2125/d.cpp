#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

int inv(int a) {
  return a <= 1 ? a : MOD - (long long)(MOD/a) * inv(MOD % a) % MOD;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<tuple<int, int, int>>> v(m+1);
	for(int i = 0; i < n; i++){
		int a, b, p, q; cin >> a >> b >> p >> q;
		v[b].emplace_back(a, p, q);
	}

	cout << 5*inv(6)%MOD << endl;

	vector<int> dp(m+1); dp[0] = 1;
	for(int i = 1; i <= m; i++) for(auto [a, p, q]: v[i]){
		dp[i] += dp[a-1]*p%MOD*inv(q)%MOD;
		dp[i] %= MOD;
	}

	cout << dp[m] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
