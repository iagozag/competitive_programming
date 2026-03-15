#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<int> g;

void solve(){
	g = vector<int>(n);
	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; g[a] |= (1<<b), g[b] |= (1<<a); }

	queue<int> q; q.push((1<<n)-1);
	vector<int> dp(1<<n, LINF), par(1<<n, -1), shot(1<<n, -1), vis(1<<n); dp[(1<<n)-1] = 0;
	while(!q.empty()){
		auto i = q.front(); q.pop();

		if(i == 0) break;

		if(vis[i]) continue;
		vis[i] = 1;

		int prev = 0;
		for(int j = 0; j < n; j++) if(i&(1<<j)){
			int nxt = prev;

			for(int k = j+1; k < n; k++) if(i&(1<<k)) nxt |= g[k];

			if(dp[nxt] > dp[i]+1)
				dp[nxt] = min(dp[nxt], dp[i]+1), par[nxt] = i, shot[nxt] = j, q.push(nxt);

			prev |= g[j];
		}
	}

	if(dp[0] == LINF){ cout << "Impossible" << endl; }
	else{
		cout << dp[0] << ": ";

		int cur = 0; vector<int> ans;
		while(cur != (1<<n)-1){
			ans.emplace_back(shot[cur]);
			cur = par[cur];
		}

		reverse(ans.begin(), ans.end());
		for(int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " \n"[i==(int)ans.size()-1];
	}
}

int32_t main(){ _
    while(cin >> n >> m and n) solve();

    exit(0);
}
