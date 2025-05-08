#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<vector<int>> g;
vector<int> alive, dist, par;
vector<int> S;

void dfs(int v, int p, bool f){
	if(f) S.emplace_back(v);
	for(auto ve: g[v]) if(ve != p and alive[ve])
		dist[ve] = dist[v]+1, par[ve] = v, dfs(ve, v, f);
}

tuple<int, int, int> diameter(int v){
	par[v] = -1;
	dist[v] = 0;
	dfs(v, -1, 1);
	int idx = v;
	for(auto i: S){
		if(dist[idx] < dist[i] or (dist[idx] == dist[i] and idx < i)) idx = i;
	}

	par[idx] = -1;
	dist[idx] = 0;
	dfs(idx, -1, 0);
	
	int idx2 = idx;
	for(auto i: S){
		if(dist[idx2] < dist[i] or (dist[idx2] == dist[i] and idx2 < i)) idx2 = i;
	}

	int cur = idx2;
	while(cur != idx){
		alive[cur] = 0;
		cur = par[cur];
	}
	alive[idx] = 0;

	S.clear();
	return {dist[idx2]+1, max(idx, idx2)+1, min(idx, idx2)+1};
}

void solve(){
	cin >> n;
	g = vector<vector<int>>(n);
	alive = vector<int>(n, 1);
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b), g[b].emplace_back(a);
	}

	vector<tuple<int, int, int>> ans;
	for(int l = 0; l < 20; l++){
		vector<tuple<int, int, int>> v;
		dist = vector<int>(n, INF);
		par = vector<int>(n, -1);
		for(int i = 0; i < n; i++) if(alive[i])
			ans.push_back(diameter(i));
	}
	sort(ans.begin(), ans.end(), greater<tuple<int, int, int>>());

	for(auto x: ans){
		auto [a, b, c] = x;
		cout << a << ' ' << b << ' ' << c << ' ';
	}
	cout << endl;
}
int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
