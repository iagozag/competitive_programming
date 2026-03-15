#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int comp(vector<string>& v){
	int n = v.size(), m = v[0].size();

	int vis[n][m]; bool can = 0;
	queue<pair<int, int>> q; 
	for(int i = 0; i < n; i++){
		if(can) break;
		for(int j = 0; j < m; j++)
			if(v[i][j] == '#'){ q.emplace(i, j); can = 1; break; }
	}

	memset(vis, 0, sizeof vis);
	while(!q.empty()){
		auto [i, j] = q.front(); q.pop();

		if(vis[i][j]) continue;
		vis[i][j] = 1;

		for(auto [a, b]: moves){
			a += i, b += j;
			if(a < 0 or a >= n or b < 0 or b >= m or v[a][b] == '.') continue;
			q.push({a, b});
		}
	}

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(v[i][j] == '#' and !vis[i][j]) return 2;

	return 1;
}

void solve(){
	int n, m, sum = 0; cin >> n >> m;

	vector<string> v(n); for(int i = 0; i < n; i++) cin >> v[i];

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(v[i][j] == '#'){
		v[i][j] = '.';
		if(comp(v) == 2){ cout << 1 << endl; return; }
		v[i][j] = '#';
		sum++;
	}

	cout << (sum <= 2 ? -1 : 2) << endl;
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


