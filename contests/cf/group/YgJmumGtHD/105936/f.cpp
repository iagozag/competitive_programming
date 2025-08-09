#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;pair<int>

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<string> v(n); pair<int, int> st; vector<pair<int, int>> cheese;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		for(int j = 0; j < m; j++){
			if(v[i][j] == 'R') st = {i, j};
			if(v[i][j] == 'Q') cheese.emplace_back(i, j);
		}
	}

	vector<vector<int>> dist(n, vector<int>(m, INF)), vis(n, vector<int>(m)); dist[st.first][st.second] = 0;
	queue<pair<int, int>> q; q.push(st);
	while(!q.empty()){
		auto [x, y] = q.front(); q.pop();
		if(vis[x][y]) continue;
		vis[x][y] = 1;
		for(auto [a, b]: moves){
			a += x, b += y;
		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
