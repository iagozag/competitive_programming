#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+1, MOD = 1e9+7;

int n;
vector<int> g[MAX], good[MAX];
int v[MAX], h[MAX];
int par[MAX][20];

bool insert_basis(int* a, int x){
	for(int j = 0; j < 20; j++){
		if(!(x&(1<<j))) continue;

		if(!a[j]){
			a[j] = x;
			return true;
		}
		x ^= a[j];
	}
	return false;
}

vector<int> build_path(const vector<int>& path, int vv){
	int b[20]; memset(b, 0, sizeof b);
	vector<int> ans;
	if(insert_basis(b, v[vv])) ans.emplace_back(vv);
	for(auto x: path) if(insert_basis(b, v[x])) ans.emplace_back(x);
	return ans;
}

void dfs(int vv, int pp){
	if(vv == 0) good[vv] = build_path(vector<int>(0), vv);
	else good[vv] = build_path(good[pp], vv);

	for(auto ve: g[vv]) if(ve != pp){
		par[ve][0] = vv, h[ve] = h[vv]+1;
		dfs(ve, vv);
	}
}

int lca_f(int a, int b){
	if(a == b) return a;
	if(h[a] < h[b]) swap(a, b);

	int diff = h[a]-h[b];
	for(int i = 0; i < 20; i++) if(diff&(1<<i)) a = par[a][i];

	int ans = 0;
	for(int i = 19; i >= 0; i--){
		if(par[a][i] == par[b][i]) ans = par[a][i];
		else a = par[a][i], b = par[b][i];
	}

	if(a == b) ans = a;

	return ans;
}

void path_basis(int a, int b, int* ba){
	int lca = lca_f(a, b);
	for(auto x: good[a]) if(h[x] >= h[lca]) insert_basis(ba, v[x]);
	for(auto x: good[b]) if(h[x] >= h[lca]) insert_basis(ba, v[x]);
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n-1; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }

	par[0][0] = 0;
	dfs(0, 0);

	for(int j = 1; j < 20; j++) for(int i = 0; i < n; i++) par[i][j] = par[par[i][j-1]][j-1];

	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int a, b, k; cin >> a >> b >> k; --a, --b;
		
		int basis[20]; memset(basis, 0, sizeof basis);
		path_basis(a, b, basis);

		for(int j = 0; j < 20; j++) if(k&(1<<j)) k ^= basis[j];

		cout << (k == 0 ? "YES" : "NO") << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
