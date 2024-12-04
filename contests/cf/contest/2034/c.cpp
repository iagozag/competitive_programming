#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m; cin >> n >> m;
	map<char, pair<int, int>> mp;
	mp['U'] = {-1, 0};
	mp['D'] = {1, 0};
	mp['L'] = {0, -1};
	mp['R'] = {0, 1};

	vector<string> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	vector<vector<int>> vis(n, vector<int>(m));
	function<int(int, int)> dfs = [&](int i, int j) -> int{
		if(i < 0 or i >= n or j < 0 or j >= m) return 1;
		if(vis[i][j]) return vis[i][j];
		if(v[i][j] == '?') return vis[i][j] = -1;
		auto [a, b] = mp[v[i][j]];
		vis[i][j] = -1;
		return vis[i][j] = dfs(i+a, j+b);
	};

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(!vis[i][j] and v[i][j] != '?')
		dfs(i, j);
		
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(!vis[i][j] and v[i][j] == '?'){
		vis[i][j] = 1;
		for(auto [a, b]: mp){
			int ni = i+b.first, nj = j+b.second;
			if(ni >= 0 and ni < n and nj >= 0 and nj < m) if(vis[ni][nj] != 1) vis[i][j] = -1; 
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(vis[i][j] != 1) ans++;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
