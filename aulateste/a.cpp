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
int memo[20][1<<20];

int dp(int v, int mask){
	auto& p = memo[v][mask];
	if(v == n-1) return p = (mask == (1<<n)-1);
	if(p != -1) return p;

	int resposta = 0;
	for(auto ve: g[v]) if(!((mask>>ve)&1)){
		int new_mask = mask|(1<<ve);
		resposta += dp(ve, new_mask);
		resposta %= MOD;
	}

	return p = resposta;
}

void solve(){
	cin >> n >> m;
	g = vector<vector<int>>(n);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b);
	}

	for(int i = 0; i < 20; i++) for(int j = 0; j < (1<<n); j++) memo[i][j] = -1;

	cout << dp(0, 1) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
