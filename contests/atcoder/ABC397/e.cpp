#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, k;
vector<vector<int>> g;
vector<int> cut;
bool cant = 0;

int dfs(int v, int p){
	if(cant) return 0;

	int child = 1, c = 0;
	for(auto ve: g[v]) if(ve != p){
		child += dfs(ve, v);
		c += cut[ve];
	}

	int rest = g[v].size()-c-1;

	if(child == k){
		if(rest > 2) cant = 1;
		else cut[v] = 1;
	} 
	else if(child > k) cant = 1;
	else if(child < k and rest > 1) cant = 1;

	return (child < k ? child : 0);
}

void solve(){
	cin >> n >> k;
	g = vector<vector<int>>(n*k), cut = vector<int>(n*k);
	for(int i = 0; i < n*k-1; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }

	cout << (!dfs(0, -1) and !cant  ? "Yes" : "No") << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
