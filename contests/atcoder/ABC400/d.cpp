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
int dist[1010][1010];
int vis[1010][1010];
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool val(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < m;
}

void solve(){
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < m; j++) v[i][j] = (s[j] == '.');
	}

	int si, sj, ei, ej; cin >> si >> sj >> ei >> ej;
	--si, --sj, --ei, --ej;

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) dist[i][j] = INF;
	memset(vis, 0, sizeof vis);

	dist[si][sj] = 0;
	priority_queue<tuple<int, int, int>> pq; pq.emplace(0, si, sj);
	while(!pq.empty()){
		auto [w, i, j] = pq.top(); pq.pop(); w *= -1;
		if(vis[i][j]) continue;
		vis[i][j] = 1;

		for(auto [a, b]: moves){
			int c = a*2+i, d = b*2+j;
			a += i, b += j;

			if(!val(a, b)) continue;

			if(v[a][b] and dist[a][b] > w) dist[a][b] = w, pq.emplace(-dist[a][b], a, b);
			else if(!v[a][b]){
				if(dist[a][b] > w+1) dist[a][b] = w+1, pq.emplace(-dist[a][b], a, b);
				if(val(c, d) and dist[c][d] > w+1) dist[c][d] = w+1, pq.emplace(-dist[c][d], c, d);
			}
		}
	}

	cout << dist[ei][ej] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
