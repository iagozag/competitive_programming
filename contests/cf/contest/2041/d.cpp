#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<pair<int, int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	pair<int, int> st, end;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < m; j++){
			v[i][j] = (s[j] != '#');
			if(s[j] == 'S') st = {i, j};
			else if(s[j] == 'T') end = {i, j};
		}
	}

	int dist[n][m][4][4];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) for(int k = 0; k < 4; k++) for(int l = 0; l < 4; l++)
		dist[i][j][k][l] = LINF;

	queue<tuple<int, int, int, int>> q; 
	dist[st.first][st.second][0][0] = 0, q.emplace(st.first, st.second, 0, 0);

	while(!q.empty()){
		auto [a, b, c, d] = q.front(); q.pop();

		for(int j = 0; j < 4; j++){
			int x = a+moves[j].first, y = b+moves[j].second;
			if(!v[x][y]) continue;

			if(j == c and d < 3 and dist[x][y][j][d+1] > dist[a][b][c][d]+1){
				dist[x][y][j][d+1] = dist[a][b][c][d]+1;
				q.emplace(x, y, j, d+1);
			} else if(j != c and dist[x][y][j][1] > dist[a][b][c][d]+1){
				dist[x][y][j][1] = dist[a][b][c][d]+1;
				q.emplace(x, y, j, 1);
			}
		}
	}


	int mi = LINF;
	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) mi = min(mi, dist[end.first][end.second][i][j]);
	cout << (mi == LINF ? -1 : mi) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
