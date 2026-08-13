#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5001, MOD = 1e9+7;

vector<vector<int>> memo;
vector<vector<int>> par;
vector<pair<int, int>> g[MAX];

void solve(){
	int n, m, t; cin >> n >> m >> t;

	for(int i = 0; i < m; i++){ int a, b, c; cin >> a >> b >> c; --a, --b; g[a].emplace_back(b, c); }

	memo = vector<vector<int>>(n, vector<int>(n+1, INF));
	par = vector<vector<int>>(n, vector<int>(n+1));

	memo[0][1] = 0;
	for(auto j = 0; j < n; j++) for(int v = 0; v < n; v++){
		for(auto [ve, w]: g[v]) if(memo[ve][j+1] > memo[v][j]+w and memo[v][j]+w <= t) memo[ve][j+1] = memo[v][j]+w, par[ve][j+1] = v;
	}

	int ans = 0;
	for(int i = 0; i <= n; i++) if(memo[n-1][i] <= t) ans = i;

	vector<int> path; int cur = n-1;
	while(cur){
		path.emplace_back(cur);
		cur = par[cur][ans], ans--;
	}
	path.emplace_back(0);
	reverse(path.begin(), path.end());

	cout << path.size() << endl;
	for(auto x: path) cout << x+1 << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
