#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<vector<int>> g;
int k;
vector<int> p, d;

vector<int> can;

void bfs(int s, int dd){
	vector<int> dist(n, INF); queue<int> q; q.push(s), dist[s] = 0;

	vector<int> vis(n);
	while(!q.empty()){
		int v = q.front(); q.pop();

		if(vis[v]) continue;
		vis[v] = 1;

		if(dist[v] < dd) can[v] = -1;
		else{
			if(can[v] != -1) can[v] = 1;
			continue;
		}
		for(auto ve: g[v]) if(dist[v]+1 < dist[ve])
			dist[ve] = dist[v]+1, q.push(ve);
	}
}

bool bfs2(int s, int dd){
	vector<int> dist(n, INF); queue<int> q; q.push(s), dist[s] = 0;

	vector<int> vis(n);
	bool exists = 0;
	while(!q.empty()){
		int v = q.front(); q.pop();

		if(vis[v]) continue;
		vis[v] = 1;

		if(dist[v] < dd){
			if(can[v] == 1) return 0;
		} else{
			exists |= (can[v] == 1);
			continue;
		}

		for(auto ve: g[v]) if(dist[v]+1 < dist[ve])
			dist[ve] = dist[v]+1, q.push(ve);
	}
	return exists;
}

void solve(){
	cin >> n >> m; g = vector<vector<int>>(n);
	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }
	cin >> k;
	p = d = vector<int>(k);
	for(int i = 0; i < k; i++) cin >> p[i] >> d[i], --p[i];

	if(!k){ cout << "Yes" << endl << string(n, '1') << endl; return; }

	can = vector<int>(n);
	for(int i = 0; i < k; i++){
		if(d[i]) bfs(p[i], d[i]);
		else if(can[p[i]] >= 0) can[p[i]] = 1;
	}

	bool ok = 1;
	for(int i = 0; i < k; i++){
		if(d[i]) ok &= (can[p[i]] != 1)&bfs2(p[i], d[i]);
		else ok &= (can[p[i]] == 1);
	}

	if(!ok){ cout << "No" << endl; return; }

	cout << "Yes" << endl;
	for(int i = 0; i < n; i++) cout << (can[i] == 1 ? 1 : 0);
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
