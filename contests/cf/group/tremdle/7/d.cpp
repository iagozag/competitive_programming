#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m; cin >> n >> m;
	map<pair<int, int>, vector<int>> mp;
	for(int i = 0; i < m; i++){
		int a, b, w; cin >> a >> b >> w; --a, --b;
		if(a > b) swap(a, b);

		mp[{a, b}].emplace_back(w);
	}

	int sz = 0;
	for(auto [a, b]: mp) sz += min(2LL, b.size());

	vector<vector<int>> bun(sz), city(n);

	int k = 0;
	for(auto& [a, b]: mp){
		sort(b.begin(), b.end(), greater<int>());
		city[a].emplace_back(k);
	}

	vector<set<int, greater<int>>> g(n+k);
	for(auto [a, b, c]: edges){
		g[a].insert({c, b});
		g[b].insert({c, a});
	}
	
	int ans = 0;
	queue<int> q;
	for(int i = 0; i < n; i++) if(g[i].size() == 1) q.push(i);
	
	while(!q.empty()){
		auto v = q.front(); q.pop();

		ans += (*g[v].begin()).first;
		
		int bun = (*g[v].begin()).second;

		for(auto ve: g[bun]){

		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
