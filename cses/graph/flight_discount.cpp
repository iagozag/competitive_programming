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

	int dist[n][2]; fill(*dist, *dist+n*2, LINF); dist[0][0] = dist[0][1] = 0;
	priority_queue<tuple<int, int, int>> pq; pq.push({0, 0, 0});
	while(!pq.empty()){
		auto [w, v, d] = pq.top(); pq.pop(); w *= -1;
		if(dist[v][d] < w) continue;

		for(auto [ve, ww]: g[v]){
			if(dist[ve][d] > w+ww) dist[ve][d] = w+ww, pq.push({-dist[ve][d], ve, d});
			if(!d and dist[ve][1] > w+ww/2) dist[ve][1] = w+ww/2, pq.push({-dist[ve][1], ve, 1});
		}
	}

	cout << min(dist[n-1][0], dist[n-1][1]) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
