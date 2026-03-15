#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

// 0 - left, 1 - up, 2 - right, 3 - down

vector<tuple<int, int, int>> moves = {{-1, 0, 3}, {1, 0, 1}, {0, -1, 2}, {0, 1, 0}};

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		for(int j = 0; j < m; j++) v[i][j] = (int)(s[j]-'A');
	}

	vector<vector<vector<int>>> dist(n+1, vector<vector<int>>(m+1, vector<int>(4, INF))), vis(n+1, vector<vector<int>>(m+1, vector<int>(4)));
	deque<tuple<int, int, int>> dq; dq.push_front({0, 0, 0}); dist[0][0][0] = 0;
	while(!dq.empty()){
		auto [i, j, d] = dq.front(); dq.pop_front();

		if(vis[i][j][d]) continue;
		vis[i][j][d] = 1;

		for(auto [a, b, nd]: moves){
			a += i, b += j;
			if(a < 0 or a >= n or b < 0 or b >= m) continue;
			int add = !((v[i][j] == 0 and d == nd) or 
						(v[i][j] == 1 and ((d == 0 and nd == 1) or (d == 1 and nd == 0) or (d == 2 and  nd == 3) or (d == 3 and nd == 2))) or
						(v[i][j] == 2 and ((d == 0 and nd == 3) or (d == 1 and nd == 2) or (d == 2 and  nd == 1) or (d == 3 and nd == 0))));

			int ndist = dist[i][j][d] + add;

			if(ndist < dist[a][b][nd]){
				dist[a][b][nd] = ndist;
				if(add) dq.push_back({a, b, nd});
				else dq.push_front({a, b, nd});
			}
		}
	}

	cout << min(dist[n-1][m-1][0] + (v[n-1][m-1] != 0), dist[n-1][m-1][1] + (v[n-1][m-1] != 1)) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
