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
	vector<int> v(n), g(n);
	for(int i = 0; i < n; i++){ int a; cin >> a; --a; v[a]++, g[i] = a; }
	
	queue<int> q; vector<int> cnt(n, 1), res(n, 1), ma(n, 0), vis(n);
	for(int i = 0; i < n; i++) if(!v[i]) q.push(i);

	while(!q.empty()){
		int ve = q.front(); q.pop();
		if(vis[ve]) continue;

		vis[ve] = 1, v[g[ve]]--, res[ve] += ma[ve], ma[ve] = 0;
		if(!v[g[ve]]) q.push(g[ve]);

		cnt[g[ve]] += cnt[ve], ma[g[ve]] = max(ma[g[ve]], cnt[ve]);
	}

	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, res[i]+ma[i]);
	cout << ans+1 << endl;
}
	

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
