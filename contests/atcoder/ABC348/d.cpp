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
vector<string> v;

vector<pair<int, int>> moves = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool val(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < m and v[i][j] != '#';
}

vector<vector<int>> bfs(int si, int sj){
	queue<pair<int, int>> q; q.push({si, sj});
	vector<vector<int>> dist(n, vector<int>(m, INF)), vis(n, vector<int>(m)); dist[si][sj] = 0;
	while(!q.empty()){
		auto [a, b] = q.front(); q.pop();

		if(vis[a][b]) continue;
		vis[a][b] = 1;

		for(auto [x, y]: moves){
			x += a, y += b;
			if(val(x, y) and dist[x][y] > dist[a][b]+1) dist[x][y] = dist[a][b]+1, q.push({x, y});
		}
	}

	return dist;
}

void solve(){
	cin >> n >> m;
	v = vector<string>(n); for(auto& x: v) cin >> x;
	int si, sj, ti, tj;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		if(v[i][j] == 'S') si = i, sj = j;
		if(v[i][j] == 'T') ti = i, tj = j;
	}

	cin >> k;
	vector<tuple<int, int, int>> en; int idx = -1; 
	for(int i = 0; i < k; i++){ 
		int a, b, c; cin >> a >> b >> c; --a, --b, en.emplace_back(a, b, c); 
		if(a == si and b == sj and en.size()) swap(en.back(), en[0]);
		if(a == ti and b == tj) idx = i;
	}
	if(idx == -1) idx = k++, en.emplace_back(ti, tj, 0);

	if(get<0>(en[0]) != si or get<1>(en[0]) != sj){ cout << "No" << endl; return; }

	vector<vector<int>> dist(k, vector<int>(k, INF));
	for(int i = 0; i < k; i++){
		auto [a, b, c] = en[i];
		vector<vector<int>> d = bfs(a, b);
		for(int j = 0; j < k; j++) dist[i][j] = min(dist[i][j], d[get<0>(en[j])][get<1>(en[j])]);
	}

	queue<int> q; q.push(0); vector<int> vis(k);
	while(!q.empty()){
		auto i = q.front(); q.pop();
		if(i == idx){ cout << "Yes" << endl; return; }

		if(vis[i]) continue;
		vis[i] = 1;

		for(int j = 0; j < k; j++){
			if(dist[i][j] <= get<2>(en[i])) q.push(j);
		}
	}

	cout << "No" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
