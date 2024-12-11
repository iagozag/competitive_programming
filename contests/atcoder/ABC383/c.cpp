#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m, d;
vector<string> v;
vector<vector<int>> vis;
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool val(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < m and v[i][j] != '#';
}


void solve(){
	cin >> n >> m >> d;
	v = vector<string>(n), vis = vector<vector<int>>(n, vector<int>(m)); for(auto& x: v) cin >> x;
	queue<pair<int, int>> q;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(v[i][j] == 'H') q.push({i, j}), vis[i][j] = d+1;

	while(!q.empty()){
		auto [i, j] = q.front(); q.pop();
		for(auto [a, b]: moves){
			a += i, b += j;
			if(!val(a, b)) continue;

			if(vis[a][b] < vis[i][j]-1) q.push({a, b}), vis[a][b] = vis[i][j]-1;
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(vis[i][j]) ans++;
	cout << ans << endl;	
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
