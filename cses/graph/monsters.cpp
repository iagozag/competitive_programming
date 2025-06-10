#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<char> dir = {'D', 'U', 'R', 'L'};
int n, m;
vector<string> v;

bool val(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < m;
}

void solve(){
	cin >> n >> m; 
	v = vector<string>(n);
	for(auto& x: v) cin >> x;

	pair<int, int> st, end = {-1, -1}; vector<pair<int, int>> monsters;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		if(v[i][j] == 'A') st = {i, j};
		else if(v[i][j] == 'M') monsters.emplace_back(i, j);
	}

	queue<pair<int, int>> q;
	int dist[n][m]; fill(*dist, *dist+n*m, INF);
	for(auto [i, j]: monsters) q.push({i, j}), dist[i][j] = 0;

	bool vis[n][m]; fill(*vis, *vis+n*m, false);
	while(!q.empty()){
		auto [x, y] = q.front(); q.pop();

		if(vis[x][y]) continue;
		vis[x][y] = 1;

		for(auto [a, b]: moves){
			a += x, b += y;
			if(!val(a, b) or v[a][b] == '#' or dist[x][y]+1 >= dist[a][b]) continue;
			dist[a][b] = dist[x][y]+1; q.push({a, b});
		}
	}

	int d2[n][m]; fill(*d2, *d2+n*m, INF);
	d2[st.first][st.second] = 0;

	q.push(st); fill(*vis, *vis+n*m, false);
	while(!q.empty()){
		auto [x, y] = q.front(); q.pop();

		if(vis[x][y]) continue;
		vis[x][y] = 1;

		for(int i = 0; i < 4; i++){
			auto [a, b] = moves[i];
			a += x, b += y;
			
			if(!val(a, b)){ end = {x, y}, q = {}; break; }

			if(v[a][b] == '#' or d2[x][y]+1 >= d2[a][b] or dist[a][b] <= d2[x][y]+1) continue;
			d2[a][b] = d2[x][y]+1; q.push({a, b});
		}
	}

	if(end.first == -1){ cout << "NO" << endl; return; }

	cout << "YES" << endl;
	cout << d2[end.first][end.second] << endl;
	auto [a, b] = end; string ans = "";
	while(a != st.first or b != st.second){
		for(int i = 0; i < 4; i++){
			auto [x, y] = moves[i]; x += a, y += b;
			if(val(x, y) and d2[x][y] == d2[a][b]-1){
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
