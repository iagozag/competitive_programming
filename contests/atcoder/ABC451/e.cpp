#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3010, MOD = 1e9+7;

vector<int> id(MAX), sz(MAX, 1);

int find(int x){ return id[x] = id[x] == x ? x : find(id[x]); }

void unio(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b], id[b] = a;
}

void no(){ cout << "No" << endl; }

vector<vector<pair<int, int>>> g(MAX);
void dfs(int v, int p, vector<int>& dist){
	for(auto [ve, w]: g[v]) if(ve != p) dist[ve] = dist[v]+w, dfs(ve, v, dist);
}

void solve(){
	iota(id.begin(), id.end(), 0);

	int n; cin >> n;
	vector<tuple<int, int, int>> v;
	for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++){
		int x; cin >> x; v.emplace_back(x, i, j);
	}

	sort(v.begin(), v.end());
	
	vector<vector<int>> dist(n, vector<int>(n, INF));

	int edges = 0;
	for(int i = 0; i < (int)v.size(); i++){
		auto [x, a, b] = v[i];
		if(find(a) != find(b)) unio(a, b), g[a].emplace_back(b, x), g[b].emplace_back(a, x), edges++;
	}

	if(edges != n-1) return no();

	for(int i = 0; i < n; i++) dist[i][i] = 0, dfs(i, i, dist[i]);

	for(int i = 0; i < (int)v.size(); i++){
		auto [x, a, b] = v[i];
		if(dist[a][b] != x) return no();
	}

	cout << "Yes" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
