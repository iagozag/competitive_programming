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
vector<vector<int>> v;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<bool>> vis;

bool val(int x, int y){
	return x >= 0 and x < n and y >= 0 and y < m and !vis[x][y];
}

bool bfs(int sx, int sy, int limit){
	queue<pair<int, int>> q; q.push({sx, sy});
	vis = vector<vector<bool>>(n, vector<bool>(m));

	while(!q.empty()){
		auto [a, b] = q.front(); q.pop();

		if(vis[a][b]) continue;
		vis[a][b] = 1;

		for(auto [x, y]: moves){
			x += a, y += b;
			if(!val(x, y)) continue;

			if(v[x][y] == 0 or (v[x][y] <= limit and (v[x][y]&limit) >= v[x][y]))
				q.push({x, y});
		}
	}

	return vis[n-1][m-1];
}

int f(int sx, int sy){
	int num = (1LL<<32)-1;
	
	for(int i = 31; i >= 0; i--)
		if(bfs(sx, sy, num-(1LL<<i))) num -= (1LL<<i);

	return num;
}

void solve(){
	cin >> n >> m;
	int a, b; cin >> a >> b; --a, --b;
	v = vector<vector<int>>(n, vector<int>(m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j];

	cout << f(0, 0) << ' ' << f(a, b) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
