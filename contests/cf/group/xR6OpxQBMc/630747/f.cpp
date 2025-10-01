#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 110, MOD = 1e9+7;

vector<int> g[MAX];
int vis[MAX], dist[MAX];

int bfs(int s){
	for(int i = 0; i < MAX; i++) vis[i] = 0, dist[i] = INF;
	dist[s] = 0;
	queue<int> q; q.push(s);

	int ans = INF;
	while(!q.empty()){
		auto v = q.front(); q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		for(auto ve: g[v]){
			if(vis[ve] and (dist[ve]+dist[v]+1)%2) ans = min(ans, dist[ve]+dist[v]+1);
			else if(!vis[ve] and dist[ve] > dist[v]+1) dist[ve] = dist[v]+1, q.push(ve);
		}
	}

	return ans;
}

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }

	int ans = INF;
	for(int i = 0; i < n; i++)
		ans = min(ans, bfs(i));

	cout << (ans != INF ? ans : -1) << endl;

	for(int i = 0; i < MAX; i++) g[i].clear();
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
