#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<char> dir = {'D', 'U', 'R', 'L'};
int n, m;
vector<string> v;
vector<vector<int>> dist;

bool val(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < m and v[i][j] != '#';
}

void solve(){
	cin >> n >> m; 
	v = vector<string>(n);
	for(auto& x: v) cin >> x;

	pair<int, int> st, end;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		if(v[i][j] == 'A') st = {i, j};
		if(v[i][j] == 'B') end = {i, j};
	}

	auto bfs = [&](int i, int j) -> void {
		queue<pair<int, int>> q; q.push({i, j});
		dist = vector<vector<int>>(n, vector<int>(m, INF));
		dist[i][j] = 0;

		while(!q.empty()){
			auto [x, y] = q.front(); q.pop();

			for(auto [a, b]: moves){
				a += x, b += y;
				if(!val(a, b) or dist[x][y]+1 >= dist[a][b]) continue;
				dist[a][b] = dist[x][y]+1; q.push({a, b});
			}
		}
	};

	bfs(st.first, st.second);

	if(dist[end.first][end.second] == INF){ cout << "NO" << endl; return; }

	cout << "YES" << endl;
	cout << dist[end.first][end.second] << endl;
	auto [a, b] = end; string ans = "";
	while(a != st.first or b != st.second){
		for(int i = 0; i < 4; i++){
			auto [x, y] = moves[i]; x += a, y += b;
			if(val(x, y) and dist[x][y] == dist[a][b]-1){
				ans += dir[i], a = x, b = y;
				break;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
