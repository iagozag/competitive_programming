#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 2e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

int n, subsize[MAX];
vector<int> g[MAX];

void dfs(int k, int p=-1) {
	subsize[k] = 1;
	for (int i : g[k]) if (i != p) {
		dfs(i, k);
		subsize[k] += subsize[i];
	}
}

int centroid(int k, int p=-1, int size=-1) {
	if (size == -1) size = subsize[k];
	for (int i : g[k]) if (i != p) if (subsize[i] > size/2)
		return centroid(i, k, size);
	return k;
}

pair<int, int> centroids(int k=0) {
	dfs(k);
	int i = centroid(k), i2 = i;
	for (int j : g[i]) if (2*subsize[j] == subsize[k]) i2 = j;
	return {i, i2};
}

int dist[MAX], par[MAX], vis[MAX];
void dfs2(int v, int p = -1){
	for(auto ve: g[v]) if(ve != p) par[ve] = v, dist[ve] = dist[v]+(!vis[ve]), dfs2(ve, v);
}

pair<int, vector<int>> f(int v){
	memset(dist, 0, sizeof dist), memset(par, 0, sizeof par), memset(vis, 0, sizeof vis);

	int sum = 0; vector<int> ans;

	dist[v] = 0, par[v] = -1;
	dfs2(v);

	int idx = v;
	for(int i = 0; i < n; i++) if(dist[idx] < dist[i]) idx = i;
	ans.emplace_back(idx), sum += dist[idx];
	while(par[idx] != -1) vis[idx] = 1, idx = par[idx];

	dist[v] = 0, par[v] = -1;
	dfs2(v);

	idx = v;
	for(int i = 0; i < n; i++) if(dist[idx] < dist[i]) idx = i;
	ans.emplace_back(idx), sum += dist[idx];
	while(par[idx] != -1) vis[idx] = 1, idx = par[idx];

	dist[v] = 0, par[v] = -1;
	dfs2(v);

	idx = v;
	for(int i = 0; i < n; i++) if(dist[idx] < dist[i]) idx = i;
	ans.emplace_back(idx), sum += dist[idx];
	while(par[idx] != -1) vis[idx] = 1, idx = par[idx];

	return make_pair(sum, ans);
}

void solve(){
	cin >> n;
	for(int i = 0; i < n-1; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }

	pair<int, int> c = centroids();

	auto [a, v] = f(c.first);	
	auto [b, w] = f(c.second);	

	if(a < b) swap(a, b), swap(v, w);

	cout << a << endl;	
	for(auto x: v) cout << x+1 << ' ';
	cout << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


