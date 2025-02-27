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
	int n, s1, s2; cin >> n >> s1 >> s2; --s1, --s2;
	vector<vector<int>> g1(n), g2(n); vector<vector<pair<int, int>>> h(n*n);
	int m1, m2; cin >> m1;
	for(int i = 0; i < m1; i++){ int a, b; cin >> a >> b; --a, --b; g1[a].emplace_back(b), g1[b].emplace_back(a); }
	cin >> m2;
	for(int i = 0; i < m2; i++){ int a, b; cin >> a >> b; --a, --b; g2[a].emplace_back(b), g2[b].emplace_back(a); }

	for(int i = 0; i < n; i++) sort(g1[i].begin(), g1[i].end()), sort(g2[i].begin(), g2[i].end());

	vector<vector<int>> mp(n, vector<int>(n, -1)); int k = 0; mp[s1][s2] = k++;
	queue<pair<int, int>> q; q.push({s1, s2}); vector<vector<int>> vis(n, vector<int>(n));
	while(!q.empty()){
		auto [a, b] = q.front(); q.pop();

		if(vis[a][b]) continue;
		vis[a][b] = 1;

		for(auto ve: g1[a]) for(auto vf: g2[b]) if(!vis[ve][vf]){
			if(mp[ve][vf] == -1) mp[ve][vf] = k++;
			int u = mp[a][b], v = mp[ve][vf];
			h[u].emplace_back(v, abs(ve-vf)), h[v].emplace_back(u, abs(a-b));
			q.push({ve, vf});
		}
	}

	priority_queue<pair<int, int>> pq; pq.push({0, mp[s1][s2]});
	vector<int> dist(n*n, LINF); dist[mp[s1][s2]] = 0; vector<int> vis2(n*n);
	while(!pq.empty()){
		auto [w, v] = pq.top(); pq.pop(); w *= -1;
		if(vis2[v]) continue;
		vis2[v] = 1;

		for(auto [ve, w2]: h[v]) if(w+w2 < dist[ve]) dist[ve] = w+w2, pq.push({-w-w2, ve});
	}

	set<int> can;
	for(int i = 0; i < n; i++){
		for(auto ve: g1[i]){
			int lb = lower_bound(g2[i].begin(), g2[i].end(), ve)-g2[i].begin();
			if(lb < (int)g2[i].size() and g2[i][lb] == ve) can.insert(i);
		}
	}

	int ans = LINF;
	for(auto x: can) ans = min(ans, (mp[x][x] == -1 ? LINF : dist[mp[x][x]]));
	cout << (ans == LINF ? -1 : ans) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
