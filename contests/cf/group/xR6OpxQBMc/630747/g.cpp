#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> id, sz;

int find(int x){ return id[x] = (id[x] == x ? x : find(id[x])); }

void unite(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b], id[b] = a;
}

void solve(){
	int n, m; cin >> n >> m;
	id = vector<int>(n), sz = vector<int>(n, 1); iota(id.begin(), id.end(), 0);
	vector<pair<int, int>> edges(m);
	for(auto& [a, b]: edges) cin >> a >> b, --a, --b;

	int q; cin >> q; vector<pair<int, int>> need; vector<int> vis(m);
	for(int i = 0; i < q; i++){
		int x; cin >> x; --x;
		vis[x] = 1, need.push_back(edges[x]);
	}
	reverse(need.begin(), need.end());

	for(int i = 0; i < m; i++) if(!vis[i]) unite(edges[i].first, edges[i].second);

	set<int> st;
	for(int i = 0; i < n; i++) st.insert(find(i));

	int tot = 0, sum = 0;
	for(auto x: st) sum += sz[x];
	for(auto x: st) tot += sz[x]*(sum-sz[x]);
	tot /= 2;

	vector<int> ans;
	for(auto [a, b]: need){
		ans.emplace_back(tot);

		a = find(a), b = find(b);
		if(a == b) continue;

		tot -= sz[a]*(sum-sz[a]), tot -= sz[b]*(sum-sz[b]-sz[a]);
		unite(a, b);

		a = find(a);
		tot += sz[a]*(sum-sz[a]);
	}

	reverse(ans.begin(), ans.end());
	for(auto x: ans) cout << x << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
