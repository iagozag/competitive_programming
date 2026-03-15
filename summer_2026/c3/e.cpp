#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int MAX = 2e5+10, LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g(MAX);
vector<int> dist(MAX);

void dfs(int v, int p){
	if(p != -1) dist[v] = dist[p]+1;
	for(auto ve: g[v]) if(ve != p) dfs(ve, v);
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}	

	dfs(0, -1);

	int idx = 0;
	for(int i = 0; i < n; i++) if(dist[idx] < dist[i]) idx = i;

	dist[idx] = 0;
	dfs(idx, -1);

	int ma = 0;
	for(int i = 0; i < n; i++) ma = max(ma, dist[i]);
	cout << ma << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;
	while(ttt--) solve();

	exit(0);
}
