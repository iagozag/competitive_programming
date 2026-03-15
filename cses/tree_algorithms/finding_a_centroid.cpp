#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<vector<int>> g;
vector<int> sz;

int dfs_sz(int v, int p){
	sz[v]++;
	for(auto ve: g[v]) if(ve != p) sz[v] += dfs_sz(ve, v);
	return sz[v];
}

int centroid(int v, int p){
	for(auto ve: g[v]) if(ve != p){
		if(sz[ve] > n/2) return centroid(ve, v);
	}
	return v;
}

void solve(){
	cin >> n;
	g.resize(n), sz.resize(n);
	for(int i = 0; i < n-1; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }
	
	dfs_sz(0, -1);

	cout << centroid(0, -1)+1 << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
