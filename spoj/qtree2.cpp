#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<pair<int, ll>> par; vector<int> dist, tin, tout;
vector<vector<pair<int, ll>>> g;

int t;
void dfs(int v, int p){
	tin[v] = t++;
	for(auto [ve, w]: g[v]) if(ve != p){
		dist[ve] = dist[v]+1, par[ve] = {v, w};
		dfs(ve, v);
	}
	tout[v] = t++;
}

bool is_ancestor(int a, int b){
	return tin[a] <= tin[b] and tout[a] >= tout[b];
}

void solve(){
	int n; cin >> n; g = vector<vector<pair<int, ll>>>(n);
	for(int i = 0; i < n-1; i++){
		int a, b; ll w; cin >> a >> b >> w; --a, --b;
		g[a].emplace_back(b, w), g[b].emplace_back(a, w);
	}

	dist = tin = tout = vector<int>(n), par = vector<pair<int, ll>>(n), t = 0;
	dfs(0, -1);

	int LOG = 0; while((1<<LOG) <= n) LOG++;
	vector<vector<pair<int, ll>>> dp(n, vector<pair<int, ll>>(LOG));
	for(int i = 0; i < n; i++) dp[i][0] = par[i];
	for(int k = 1; k < LOG; k++) for(int i = 0; i < n; i++) 
		dp[i][k] = {dp[dp[i][k-1].first][k-1].first, dp[dp[i][k-1].first][k-1].second+dp[i][k-1].second};

	string s;
	while(cin >> s and s != "DONE"){
		if(s[0] == 'D'){
			int a, b; cin >> a >> b; --a, --b;
			if(dist[a] > dist[b]) swap(a, b);

			ll ans = 0; int need = dist[b]-dist[a];
			for(int j = LOG-1; j >= 0; j--) if(need&(1<<j)) ans += dp[b][j].second, b = dp[b][j].first;

			if(a == b){ cout << ans << endl; continue; }

			for(int j = LOG-1; j >= 0; j--) if(dp[a][j].first != dp[b][j].first) 
				ans += dp[a][j].second+dp[b][j].second, a = dp[a][j].first, b = dp[b][j].first;

			cout << ans+dp[a][0].second+dp[b][0].second << endl;
		} else{
			int a, b, k; cin >> a >> b >> k; --a, --b, --k;

			if(is_ancestor(a, b)){
				int need = (dist[b]-dist[a])-k;	
				for(int j = LOG-1; j >= 0; j--) if(need&(1<<j)) b = dp[b][j].first;
				cout << b+1 << endl;
				continue;
			} else if(is_ancestor(b, a)){
				for(int j = LOG-1; j >= 0; j--) if(k&(1<<j)) a = dp[a][j].first;
				cout << a+1 << endl;
				continue;
			}

			int pa = a, pb = b;

			bool sw = 0;
			if(dist[a] > dist[b]) swap(a, b), sw = 1;

			int da = 0, db = 0, need = dist[b]-dist[a];
			for(int j = LOG-1; j >= 0; j--) if(need&(1<<j)) db += (1<<j), b = dp[b][j].first;

			for(int j = LOG-1; j >= 0; j--) if(dp[a][j].first != dp[b][j].first) 
				da += (1<<j), db += (1<<j), a = dp[a][j].first, b = dp[b][j].first;
			da++, db++;

			if(sw) swap(da, db);	

			if(k <= da){
				for(int j = LOG-1; j >= 0; j--) if(k&(1<<j)) pa = dp[pa][j].first;
				cout << pa+1 << endl;
			} else{
				k -= da;
				need = (dist[pb]-dist[dp[a][0].first])-k;	
				for(int j = LOG-1; j >= 0; j--) if(need&(1<<j)) pb = dp[pb][j].first;
				cout << pb+1 << endl;
			}
		}
	}
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
