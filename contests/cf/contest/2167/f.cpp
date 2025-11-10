#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, k, ans;
vector<vector<int>> g;

int dfs(int v, int p){
	ans++;

	int child = 0;
	vector<int> ch;
	for(auto ve: g[v]) if(ve != p){
		int chve = dfs(ve, v);
		child += chve, ch.emplace_back(chve);
	}

	if(v) ch.emplace_back(n-child-1);

	for(auto ve : ch) if(n-ve >= k) ans += ve;

	return child+1;
}

void solve(){
	ans = 0;
	cin >> n >> k; g = vector<vector<int>>(n);
	for(int i = 0; i < n-1; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }

	dfs(0, 0);

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
