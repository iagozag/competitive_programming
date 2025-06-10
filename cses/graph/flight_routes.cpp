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
	int n, m, k; cin >> n >> m >> k;
	vector<vector<pair<int, int>>> g(n);
	for(int i = 0; i < m; i++){
		int a, b, w; cin >> a >> b >> w; --a, --b;
		g[a].emplace_back(b, w);
	}

	vector<priority_queue<int>> dist(n); dist[0].push(0);
	priority_queue<pair<int, int>> pq; pq.push({0, 0});
	while(!pq.empty()){
		auto [w, v] = pq.top(); pq.pop(); w *= -1;
		if(w > dist[v].top()) continue;

		for(auto [ve, ww]: g[v]){
			if(dist[ve].size() < k) dist[ve].push(w+ww), pq.push({-w-ww, ve});
			else if(dist[ve].top() > w+ww) dist[ve].pop(), dist[ve].push(w+ww), pq.push({-w-ww, ve});
		}
	}

	vector<int> ans;
	while(!dist[n-1].empty()) ans.emplace_back(dist[n-1].top()), dist[n-1].pop();
	reverse(ans.begin(), ans.end());
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
