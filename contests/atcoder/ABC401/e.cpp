#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> id, sz;

int find(int x){
	return id[x] = (id[x] == x ? x : find(id[x]));
}

void unio(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	id[b] = a, sz[a] += sz[b];
}

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n); id = vector<int>(n); iota(id.begin(), id.end(), 0); sz = vector<int>(n, 1);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	vector<int> ans(n);

	vector<int> vis(n); int cnt = 0;
	for(auto ve: g[0]){
		cnt++, vis[ve] = -1;
	}

	cout << cnt << endl;
	for(int v = 1; v < n; v++){
		if(vis[v] == -1) vis[v] = 1, cnt--;
		for(auto ve: g[v]){
			if(ve < v) unio(ve, v);
			else if(vis[ve] != -1){
				cnt++, vis[ve] = -1;
			}
		}

		if(sz[find(0)] == v+1) cout << cnt << endl;
		else cout << -1 << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
