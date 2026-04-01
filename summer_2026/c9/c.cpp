#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, MOD = 1e9+7;

int comp[MAX], in[MAX], cyc[MAX], child[MAX], vis[MAX];
vector<int> g[MAX];
vector<int> comps[MAX][2];

void dfs(int v, int k){
	comp[v] = k;
	for(auto ve: g[v]) if(comp[ve] == -1) dfs(ve, k);
}

void dfs2(int v){
	vis[v] = 1;
	if(vis[child[v]] == 1){
		int cur = child[v];
		while(!cyc[cur]) cyc[cur] = 1, cur = child[cur];

	}
	else dfs2(child[v]);

	vis[v] = 2;
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){ int a; cin >> a; --a, child[i] = a, g[a].emplace_back(i), g[i].emplace_back(a), in[a]++; }

	int k = 0; fill(begin(comp), begin(comp)+n, -1);
	for(int i = 0; i < n; i++) if(comp[i] == -1) dfs(i, k++);
	for(int i = 0; i < n; i++) if(!vis[i]) dfs2(i);

	for(int i = 0; i < n; i++){
		if(!in[i]) comps[comp[i]][0].emplace_back(i);
		else if(cyc[i]) comps[comp[i]][1].emplace_back(i);
	}

	if(k == 1 and !comps[0][0].size()){ cout << 0 << endl; return; }

	set<pair<int, int>> ans;
	for(int i = 0; i < k; i++){
		int szh = comps[i][0].size();
		for(int j = 0; j < szh-1; j++) ans.insert({comps[i][0][j], comps[i][0][j+1]});
		ans.insert({comps[i][1][0], 
						 (comps[(i+1)%k][0].size() ? comps[(i+1)%k][0][0] : comps[(i+1)%k][1][0])});
	}

	cout << ans.size() << endl;
	for(auto [a, b]: ans) cout << a+1 << ' ' << b+1 << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
