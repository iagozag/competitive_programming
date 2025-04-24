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
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(n));
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		g[a][b] = g[b][a] = 1;
	}

	vector<int> dp(1<<(n/2));
	for(int i = 0; i < (1<<(n/2)); i++){
		int mask = (1<<(n/2))-1;
		for(int j = 0; j < n/2; j++) if((i>>j)&1)
			for(int k = 0; k < n/2; k++) if(g[j][k] and ((mask>>k)&1)) mask -= 1<<k;

		for(int j = 0; j < n/2; j++) if(!((i>>j)&1)){
			dp[i|(1<<j)] = max(dp[i|(1<<j)], dp[i]+((mask>>j)&1));
		}
	}

	int ans = 0, opt1 = 0, opt2 = 0; vector<int> S;
	for(int i = 0; i < (1<<((n+1)/2)); i++){
		int ok = 1;
		for(int j = n/2; j < n; j++) if((i>>(j-n/2))&1){
			for(int k = j+1; k < n; k++) if(((i>>(k-n/2))&1) and g[j][k]) ok = 0;
		}

		if(!ok) continue;

		int mask = (1<<(n/2))-1;
		for(int j = n/2; j < n; j++) if((i>>(j-n/2))&1){
			for(int k = 0; k < n/2; k++) if(g[j][k] and ((mask>>k)&1)) mask -= 1<<k;
		}

		if(ans < (__builtin_popcount(i)+dp[mask])){
			ans = __builtin_popcount(i)+dp[mask], opt1 = i, opt2 = mask;
		}
	}

	int can = 1;
	while(can){
		can = 0;
		for(int i = 0; i < n/2; i++) if((opt2>>i)&1 and dp[opt2] == dp[opt2-(1<<i)])
			can = 1, opt2 -= 1<<i;
	}

	for(int j = n/2; j < n; j++) if((opt1>>(j-n/2))&1) S.emplace_back(j);
	for(int j = 0; j < n/2; j++) if((opt2>>j)&1) S.emplace_back(j);

	cout << ans << endl;
	for(auto x: S) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
