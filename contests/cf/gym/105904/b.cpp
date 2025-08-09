#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
#define int ll

const int LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m, k;
vector<vector<pair<int, int>>> g;
vector<int> loc;
vector<int> dist, d;

bool good(int x){
	d = vector<int>(n, LINF);
	priority_queue<pair<int, int>> pq; pq.push({x, 0}); d[0] = -x;
	while(!pq.empty()){
		auto [w, v] = pq.top(); pq.pop(); w *= -1;
		if(d[v] < w) continue;

		for(auto [ve, ww]: g[v]) if(d[v]+ww < d[ve] and d[v]+ww <= dist[ve]){
			d[ve] = d[v]+ww, pq.push({-d[ve], ve});
		}
	}

	return d[n-1] != LINF;
}

int32_t main(){ _
	cin >> n >> m >> k;
	g = vector<vector<pair<int, int>>>(n);
	for(int i = 0; i < m; i++){
		int a, b, c; cin >> a >> b >> c; --a, --b;
		g[a].push_back({b, c}), g[b].push_back({a, c});
	}

	priority_queue<pair<int, int>> pq;
	loc = vector<int>(k); dist = vector<int>(n, LINF);
	for(auto& x: loc){
		cin >> x; --x;
		pq.push({0, x}), dist[x] = 0;
	}

	while(!pq.empty()){
		auto [w, v] = pq.top(); pq.pop(); w *= -1;
		if(dist[v] < w) continue;

		for(auto [ve, ww]: g[v]) if(dist[v]+2*ww < dist[ve]){
			dist[ve] = dist[v]+2*ww, pq.push({-dist[ve], ve});
		}
	}

	int l = 0, r = 1e18, ans = r;
	while(l <= r){
		int mid = (l+r)/2;

		if(good(mid)) ans = mid, r = mid-1;
		else l = mid+1;
	}

	cout << ans << endl;

	exit(0);
};
