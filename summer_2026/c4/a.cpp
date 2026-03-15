#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

int n, m;
vector<vector<pair<int, int>>> g(MAX);
vector<vector<int>> dp(MAX, vector<int>(2, LINF));

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){ int a, b, c; cin >> a >> b >> c; --a, --b; g[a].emplace_back(b, c); }

	dp[0][0] = 0;
	priority_queue<tuple<int, int, int>> pq; pq.push({0, 0, 0});
	while(!pq.empty()){
		auto [w, v, t] = pq.top(); pq.pop(); w *= -1;

		if(w > dp[v][t]) continue;

		for(auto [ve, ww]: g[v]){
			if(w+ww < dp[ve][t]) dp[ve][t] = w+ww, pq.push({-dp[ve][t], ve, t});
			if(t == 0 and w+ww/2 < dp[ve][1]) dp[ve][1] = w+ww/2, pq.push({-dp[ve][1], ve, 1});
		}
	}

	cout << dp[n-1][1] << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


