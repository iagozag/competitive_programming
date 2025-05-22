#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<pair<int, int>> moves = {{2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

void solve(){
	int n; cin >> n;

	vector<vector<int>> dist(n, vector<int>(n, INF)); dist[0][0] = 0;
	queue<pair<int, int>> q; q.push({0, 0});
	while(!q.empty()){
		auto [a, b] = q.front(); q.pop();
		for(auto [x, y]: moves){
			x += a, y += b;
			if(x < 0 or x >= n or y < 0 or y >= n) continue;
			if(dist[x][y] > dist[a][b]+1) dist[x][y] = dist[a][b]+1, q.push({x, y});
		}
	}

	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cout << dist[i][j] << " \n"[j==n-1];
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
