#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, T;
vector<pair<int, int>> g[MAX];
vector<int> times;
vector<int> pos[MAX];
int dist[MAX];

void solve(){
	cin >> n >> T;
	for(int i = 0; i < T; i++){
		int m; cin >> m;
		for(int j = 0; j < m; j++){
			int a, b; cin >> a >> b; --a, --b;
			g[a].emplace_back(i, b), g[b].emplace_back(i, a);
		}
	}
	for(int i = 0; i < n; i++) sort(g[i].begin(), g[i].end());

	int ttt; cin >> ttt;
	for(int i = 0; i < ttt; i++){ int x; cin >> x; --x; pos[x].emplace_back(i+1); }

	for(int i = 0; i < MAX; i++) dist[i] = LINF;

	dist[0] = 0;
	priority_queue<pair<int, int>> pq; pq.emplace(0, 0);
	while(!pq.empty()){
		auto [t, v] = pq.top(); pq.pop(); t *= -1;

		if(t > dist[v]) continue;
		if(t >= ttt) continue;

		for(auto [tt, ve]: g[v]){
			auto ub = upper_bound(pos[tt].begin(), pos[tt].end(), t);
			if(ub != pos[tt].end() and dist[ve] > *ub) dist[ve] = *ub, pq.emplace(-dist[ve], ve);
		}
	}

	cout << (dist[n-1] != LINF ? dist[n-1] : -1) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
