#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

// 0 = left, 1 = down, 2 = right, 3 = up

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<tuple<int, int, int, int, int>> rect(k);
	for(auto& [a, b, c, d, e]: rect) cin >> a >> b >> c >> d >> e, --a, --b, --c, --d;

	vector<vector<int>> g(k+4);
	auto add_edge = [&](int a, int b) -> void{
		g[a].emplace_back(b), g[b].emplace_back(a);
	};

	for(int i = 0; i < k; i++){
		auto [r, c, r2, c2, g1] = rect[i];
		if(c == 0) add_edge(i+4, 0);
		if(c2 == m-1) add_edge(i+4, 2);
		if(r == 0) add_edge(i+4, 3);
		if(r2 == n-1) add_edge(i+4, 1);

		for(int j = i+1; j < k; j++){
			auto [r3, c3, r4, c4, g2] = rect[j];
			if(!(r-1 > r4 or r2+1 < r3 or c-1 > c4 or c2+1 < c3)) 
				add_edge(i+4, j+4);
		}
	}

	auto min_path = [&](int s, int t) -> int{
		vector<int> dist(k+4, LINF); dist[s] = 0;
		priority_queue<pair<int, int>> pq; pq.push({0, s});

		while(!pq.empty()){
			auto [w, v] = pq.top(); pq.pop(); w *= -1;
			if(dist[v] < w) continue;

			for(auto ve: g[v]){
				int cost = 0;
				if(ve >= 4) cost = get<4>(rect[ve-4]);
				if(dist[ve] > w+cost) dist[ve] = w+cost, pq.push({-dist[ve], ve});
			}
		}

		return dist[t];
	};

	int ans = LINF;
	ans = min(ans, min_path(0, 2)); // left-right
	ans = min(ans, min_path(0, 3)); // left-up
	ans = min(ans, min_path(1, 3)); // down-up
	ans = min(ans, min_path(1, 2)); // down-right

	cout << (ans == LINF ? -1 : ans) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
