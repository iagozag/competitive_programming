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

int find(int x){
	return id[x] = (id[x] == x ? x : find(id[x]));
}

void unio(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	id[b] = a, sz[a] += sz[b];
}

void solve(){
	int n, m; cin >> n >> m;
	id = vector<int>(n); sz = vector<int>(n, 1); iota(id.begin(), id.end(), 0);

	vector<pair<int, int>> edges;
	for(int i = 0; i < m; i++){
		int k, p; cin >> k;
		if(k == 0) continue;
		cin >> p; --p;
		for(int j = 0; j < k-1; j++){ int x; cin >> x; --x; edges.emplace_back(p, x); }
	}

	for(auto [a, b]: edges) unio(a, b);

	for(int i = 0; i < n; i++) cout << sz[find(i)] << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
