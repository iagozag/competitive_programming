#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

int n;
vector<int> g[MAX];
int fact[MAX];

int dfs(int v, int p){
	int tot = 1, child = g[v].size()-(v!=0);

	for(auto ve: g[v]) if(ve != p){
		tot *= dfs(ve, v), tot %= MOD;
	}

	int qnt = (v == 0 ? n : child+1);
	return fact[child]*qnt%MOD*tot%MOD;
}

void solve(){
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b), g[b].emplace_back(a);
	}

	cout << dfs(0, 0)%MOD << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

	fact[0] = 1;
	for(int i = 1; i < MAX; i++) fact[i] = fact[i-1]*i%MOD;

    while(ttt--) solve();

    exit(0);
}
