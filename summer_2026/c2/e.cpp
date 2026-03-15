#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10, MOD = 1e9+7;

vector<int> sz(MAX), id(MAX), vis(MAX);

int find(int x){
	return id[x] = (id[x] == x ? id[x] : find(id[x]));
}

void unio(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	id[b] = a, sz[a] += sz[b];
}

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n);
	for(int i = 0; i < n; i++){
		int k; cin >> k;
		for(int j = 0; j < k; j++){ int x; cin >> x; --x, v[i].emplace_back(x); }
		sort(v[i].begin(), v[i].end());
	}

	for(int i = 0; i < MAX; i++) sz[i] = 1, id[i] = i;

	vector<int> order(n); iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int a, int b){
		return v[a].size() < v[b].size();
	});

	int pi = -1, pj = -1;
	for(auto i: order){
		for(int j = 1; j < (int)v[i].size(); j++) unio(v[i][j-1], v[i][j]);

		if((int)v[i].size() and sz[find(v[i][0])] > v[i].size()){ pi = i; break; }
	}

	if(pi == -1){ cout << "NO" << endl; return; }

	for(auto x: v[pi]) vis[x] = 1;

	for(auto j: order) if(pi != j){
		int shared = 0, unique = 0;
		for(auto x: v[j]){
			if(vis[x]) shared++;
			else unique++;
		}

		if((int)v[pi].size() > shared and shared and unique){ pj = j; break; }
	}
	
	cout << "YES" << endl;
	cout << pi+1 << ' ' << pj+1 << endl;
}

int32_t main(){ _
	int ttt = 1;
    while(ttt--) solve();

    exit(0);
}
