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
	vector<vector<int>> g(n);
	for(int i = 0; i < n-1; i++){ int a, b; cin >> a >> b; --a, b--; g[a].emplace_back(b), g[b].emplace_back(a); }

	int ans = 0; vector<int> leaf;
	for(int i = 0; i < n; i++) if(g[i].size() == 1) leaf.emplace_back(i);
	ans = (int)leaf.size()*(n-(int)leaf.size());

	vector<int> dist(n, INF), vis(n); queue<int> q;
	for(auto x: leaf) q.push(x), dist[x] = 0;
	while(!q.empty()){
		int v = q.front(); q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		for(auto ve: g[v]) if(dist[ve] > dist[v]+1) dist[ve] = dist[v]+1, q.push(ve);
	}

	int qnt = 0;
	for(int i = 0; i < n; i++) if(dist[i] >= 2) qnt++;
	for(int i = 0; i < n; i++){
		if(dist[i] == 1){
			int ok = 0;
			for(auto ve: g[i]) ok += (dist[ve] == 1);
			if(ok) ans += qnt-1;
		}
		if(dist[i] == 2) ans += qnt-1;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
