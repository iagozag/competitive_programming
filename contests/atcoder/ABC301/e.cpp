#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m, t;
vector<string> v;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool val(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < m and v[i][j] != '#';
}

vector<vector<int>> bfs(int i, int j){
	vector<vector<int>> dist(n, vector<int>(m, INF));
	queue<pair<int, int>> q; q.push({i, j}); dist[i][j] = 0;

	while(!q.empty()){
		auto [a, b] = q.front(); q.pop();
		
		for(auto [x, y]: moves){
			x += a, y += b;
			if(val(x, y) and dist[x][y] > dist[a][b]+1) dist[x][y] = dist[a][b]+1, q.push({x, y});
		}
	}

	return dist;
}

void solve(){
	cin >> n >> m >> t;
	v = vector<string>(n); for(auto& x: v) cin >> x;
	pair<int, int> start, goal;
	vector<pair<int, int>> candies;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		if(v[i][j] == 'S') start = {i, j};
		else if(v[i][j] == 'G') goal = {i, j};
	}
	candies.emplace_back(start), candies.emplace_back(goal);

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
		if(v[i][j] == 'o') candies.emplace_back(i, j);

	int len = (int)candies.size();

	vector<vector<int>> dist(len, vector<int>(len, INF));
	for(int i = 0; i < len; i++){
		auto [a, b] = candies[i];
		dist[i][i] = 0;
		vector<vector<int>> d = bfs(a, b);
		for(int j = 0; j < len; j++)  if(j != i)
			dist[i][j] = min(dist[i][j], d[candies[j].first][candies[j].second]),
			dist[j][i] = dist[i][j];
	}

	vector<vector<int>> dp(1<<len, vector<int>(len, INF)); dp[1][0] = 0LL;
	for(int i = 1; i < (1<<len); i++){
		for(int j = 0; j < len; j++) if(!((1<<j)&i)){
			for(int k = 0; k < len; k++) if(((1<<k)&i) and dp[i][k] <= t) dp[i|(1<<j)][j] = min(dp[i|(1<<j)][j], dp[i][k]+dist[k][j]);
		}
	}

	int ans = -1;
	for(int i = 1; i < (1<<len); i++) if(i&(2LL) and dp[i][1] <= t) ans = max(ans, (int)__builtin_popcount(i));
	cout << ans-(ans == -1 ? 0 : 2) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
