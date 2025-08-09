#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define int ll

typedef long long ll;

const int MAX = 5e5+10;
const int LINF = 0x3f3f3f3f3f3f3f3fll;

int dist[MAX][3]; 

int32_t main(){ _
	int n, c, p; cin >> n >> c >> p;
	vector<vector<tuple<int, int, int>>> g(n);
	for(int i = 0; i < c+p; i++){
		int a, b, w; cin >> a >> b >> w; --a, --b;
		if(i < c) g[a].emplace_back(b, w, 0);
		else g[a].emplace_back(b, w, 1), g[b].emplace_back(a, w, 1);
	}

	for(int i = 0; i < MAX; i++) for(int j = 0; j < 3; j++) dist[i][j] = LINF;
	dist[0][0] = 0;
	priority_queue<tuple<int, int, int>> pq; pq.emplace(0, 0, 0);
	while(!pq.empty()){
		auto [w, v, op] = pq.top(); pq.pop(); w *= -1;
		if(w > dist[v][op]) continue;

		if(op < 2 and dist[v][op+1] > w) dist[v][op+1] = w, pq.emplace(-w, v, op+1);

		for(auto [ve, ww, t]: g[v]){
			if((op == 1 and t == 0) or (op != 1 and t == 1)){
				if(dist[ve][op] > w+ww) dist[ve][op] = w+ww, pq.emplace(-w-ww, ve, op);
			}
		}
	}

	cout << dist[n-1][2] << endl;

	exit(0);
}
