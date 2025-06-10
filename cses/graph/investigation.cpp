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

	// w, qnt, min, max
	vector<tuple<int, int, int, int>> dist(n, {LINF, 0, INF, 0}); dist[0] = {0, 1, 0, 0};
	priority_queue<tuple<int, int, int, int, int>> pq; pq.push({0, 1, 0, 0, 0});
	while(!pq.empty()){
		auto [w, qnt, mi, ma, v] = pq.top(); pq.pop(); w *= -1;
		if(w > get<0>(dist[v])) continue;

		for(auto [ve, ww]: g[v]){
			if(get<0>(dist[ve]) > w+ww) 
				dist[ve] = {w+ww, qnt, mi+1, ma+1},
				pq.push({-w-ww, qnt, mi+1, ma+1, ve});
			else if(get<0>(dist[ve]) == w+ww) 
				dist[ve] = {w+ww, (qnt+get<1>(dist[ve]))%MOD, min(mi+1, get<2>(dist[ve])), max(ma+1, get<3>(dist[ve]))};
		}
	}

	auto [a, b, c, d] = dist[n-1];
	cout << a << ' ' << b << ' '  << c << ' ' << d << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
