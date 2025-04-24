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

int bfs(int s){
	queue<int> q; q.push(s);
	vector<int> dist(n+63, LINF); dist[s] = 0;
	vector<int> par(n+63, -1);
	int mi = LINF;
	while(!q.empty()){
		auto v = q.front(); q.pop();

		for(auto ve: g[v]){
			if(dist[ve] == LINF) dist[ve] = dist[v]+1, par[ve] = v, q.push(ve);
			else if(par[v] != ve and par[ve] != v) mi = min(mi, (dist[v]+dist[ve]+1 > 4 ? dist[v]+dist[ve]+1 : LINF));
		}
	}

	return mi;
}

void solve(){
	cin >> n;
	g = vector<vector<int>>(n+63);
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		for(int j = 0; j < 63; j++) if((x>>j)&1) g[j].emplace_back(i+63), g[i+63].emplace_back(j);
	}

	int ans = LINF;
	for(int i = 0; i < 63; i++){
		if(g[i].size() > 2){ ans = 3; break; }
		ans = min(ans, bfs(i)/2);
	}


	cout << (ans > n ? -1 : ans) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
