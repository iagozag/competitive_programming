#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	for(int i = 0; i < m; i++){
		int a, b, w; cin >> a >> b >> w; --a, --b;
		g[a].emplace_back(b, w);
	}

	int dist[n]; for(int i = 0; i < n; i++) dist[i] = LINF;
	dist[0] = 0;
	priority_queue<pair<int, int>> pq; pq.push({0, 0});
	while(!pq.empty()){
		auto [w, v] = pq.top(); pq.pop(); w *= -1;
		if(w > dist[v]) continue;

		for(auto [ve, ww]: g[v]) if(dist[ve] > dist[v]+ww) dist[ve] = dist[v]+ww, pq.push({-dist[ve], ve});
	}

	for(int i = 0; i < n; i++) cout << dist[i] << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
