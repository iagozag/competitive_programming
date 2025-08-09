#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<vector<int>> g;
int dp[1<<21][21];

int f(int mask, int v){
	if(!(mask&(1<<v))){ cout << "NO"; exit(0); }
	if(v == 0) return dp[mask][v] = (mask == 1);

	if(dp[mask][v] != -1) return dp[mask][v];

	int ans = 0;
	cerr << mask << ' ' << v << endl;
	for(auto ve: g[v]) if(mask&(1<<ve)){
		ans += f(mask^(1<<v), ve);
		ans %= MOD;
	}

	return dp[mask][v] = ans;
}

void solve(){
	cin >> n >> m;
	g = vector<vector<int>>(n);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[b].emplace_back(a);
	}

	for(int i = 0; i < (1<<n); i++) for(int j = 0; j < n; j++)
		dp[i][j] = -1;

	cout << f((1<<n)-1, n-1) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
