#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int find(int x, vector<int>& id){
	return (id[x] == x ? x : id[x] = find(id[x], id));
}

void unio(int a, int b, vector<int>& id, vector<int>& sz){
	a = find(a, id), b = find(b, id);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	id[b] = a, sz[a] += sz[b];
}

void solve(){
	int n, m1, m2; cin >> n >> m1 >> m2;
	vector<int> id(n), sz(n, 1); iota(id.begin(), id.end(), 0);
	vector<vector<int>> f(n), g(n); vector<pair<int, int>> edgesf, edgesg;
	for(int i = 0; i < m1; i++){ int a, b; cin >> a >> b; --a, --b; edgesf.emplace_back(a, b); }
	for(int i = 0; i < m2; i++){ int a, b; cin >> a >> b; --a, --b; edgesg.emplace_back(a, b); }

	for(auto [a, b]: edgesg) unio(a, b, id, sz);

	int ans = 0; vector<int> id2(n), sz2(n, 1); iota(id2.begin(), id2.end(), 0); 
	for(auto [a, b]: edgesf){
		if(find(a, id) != find(b, id)) ans++;
		else unio(a, b, id2, sz2);
	}

	vector<vector<int>> comp(n);
	for(int i = 0; i < n; i++) comp[find(i, id)].emplace_back(i);

	for(int i = 0; i < n; i++){
		for(int j = 1; j < (int)comp[i].size(); j++) if(find(comp[i][j], id2) != find(comp[i][0], id2)) 
			ans++, unio(comp[i][j], comp[i][0], id2, sz2);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
