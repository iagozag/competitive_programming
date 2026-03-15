#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m, k;
vector<string> black, v;
vector<vector<int>> dist, color;
map<int, pair<int, int>> moves;


void dfs(int i, int j){
	dist[i][j] = -2;

	auto [a, b] = moves[v[i][j]];
	a += i, b += j;
	if(dist[a][b] == -2){
		color[i][j] = k++;
		dist[i][j] = 0;
		return;
	} 
	else if(dist[a][b] == -1) dfs(a, b);

	dist[i][j] = dist[a][b]+1;
	color[i][j] = color[a][b];
}

void solve(){
	cin >> n >> m;
	black = v = vector<string>(n);
	color = vector<vector<int>>(n, vector<int>(m));
	dist = vector<vector<int>>(n, vector<int>(m, -1));

	for(int i = 0; i < n; i++) cin >> black[i];
	for(int i = 0; i < n; i++) cin >> v[i];

	k = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(dist[i][j] == -1) dfs(i, j);

	vector<int> sz(k); int ma = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(dist[i][j] == 0){
		auto [a, b] = moves[v[i][j]];
		sz[color[i][j]] = dist[i+a][j+b]+1;
		ma += sz[color[i][j]];
	}

	set<pair<int, int>> st;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		if(black[i][j] == '0') st.insert(make_pair(color[i][j], dist[i][j]%sz[color[i][j]]));
	}

	cout << ma << ' ' << st.size() << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	moves['U'] = {-1, 0};
	moves['L'] = {0, -1};
	moves['R'] = {0, 1};
	moves['D'] = {1, 0};

    while(ttt--) solve();

    exit(0);
}
