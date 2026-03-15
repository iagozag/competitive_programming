#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e3+10, MOD = 1e9+7;

int n;
vector<int> g[MAX];
int dist[MAX], par[MAX];

void dfs(int v, int p){
	par[v] = p;
	for(auto ve: g[v]) if(ve != p) dist[ve] = dist[v]+1, dfs(ve, v);
}

void solve(){
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a);
	}

	dfs(0, -1);

	int idx = 0;
	for(int i = 1; i < n; i++) if(dist[idx] < dist[i]) idx = i;

	dist[idx] = 0;
	dfs(idx, -1);

	int idx2 = idx;
	for(int i = 0; i < n; i++) if(dist[idx2] < dist[i]) idx2 = i;

	int d = dist[idx2]+1, cur = idx2; pair<int, int> c = {cur, -1};
	while(cur != -1){
		if(dist[cur] == (d-1)/2){ c.first = cur; break; }
		if(d%2 == 0 and dist[cur] == d/2) c.second = cur;

		cur = par[cur];
	}

	vector<pair<int, int>> ans;
	if(d&1){
		for(int i = 0; i <= d/2; i++) ans.emplace_back(c.first, i);
	} else if(d%4 == 0){
		for(int i = 1; i < d/2; i += 2) ans.emplace_back(c.first, i), ans.emplace_back(c.second, i); 
	} else{
		for(int i = 1; i <= d/2; i += 2) ans.emplace_back(c.first, i), ans.emplace_back(c.second, i); 
	}

	cout << ans.size() << endl;
	for(auto [a, b]: ans) cout << a+1 << ' ' << b << endl;

	memset(dist, 0, sizeof dist);
	memset(par, 0, sizeof par);
	for(int i = 0; i < n; i++) g[i].clear();
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
