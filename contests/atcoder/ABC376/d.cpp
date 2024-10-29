#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b);
	}

	vector<int> vis(n), dist(n, INF);
	queue<int> q; q.push(0), dist[0] = 0;
	while(!q.empty()){
		auto v = q.front(); q.pop();
		if(vis[v]) continue;
		vis[v] = 1;

		for(auto ve: g[v]){
			if(dist[ve] == dist[v]-1) continue;
			if(dist[v]+1 < dist[ve]) q.push(ve), dist[ve] = dist[v]+1;
			else if(ve == 0){ cout << dist[v]+1 << endl; return; }
		}
	}
	cout << -1 << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
