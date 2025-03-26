#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, t, r;
vector<vector<int>> g;

bool dfs(int v, int p, int rnd){
	if(g[v].size() == 1) return !rnd;

	int can = !rnd;
	for(auto ve: g[v]) if(ve != p){
		int x = dfs(ve, v, !rnd);
		if(rnd) can |= x;
		else can &= x;
	}

	return can;
}

void solve(){
	cin >> n >> t; g = vector<vector<int>>(n);
	for(int i = 0; i < n-1; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }
	cin >> r; --r;

	cout << (dfs(r, -1, 1) ? "Ron" : "Hermione") << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
