
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(int i, int j, vector<vector<int>>& v, vector<vector<int>>& vis){
	int sum = v[i][j]; vis[i][j] = 1;
	for(auto [a, b]: moves){
		a += i, b += j;
		if(a < 0 or a >= n or b < 0 or b >= m or !v[a][b] or vis[a][b]) continue;
		sum += dfs(a, b, v, vis);
	}

	return sum;
}

void solve(){
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m)), vis(n, vector<int>(m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j];

	int ans = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(!vis[i][j] and v[i][j]){
		ans = max(ans, dfs(i, j, v, vis));
	}

	cout << ans << endl;
}

int32_t main(){
	int ttt; cin >> ttt;
	while(ttt--) solve();

	exit(0);
}
