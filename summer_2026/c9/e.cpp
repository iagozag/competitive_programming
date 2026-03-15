#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve(){
	int n; cin >> n;
	int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; --r1, --r2, --c1, --c2;
	vector<string> v(n); for(auto& x: v) cin >> x;

	int vis[n][n]; queue<pair<int, int>> q; q.emplace(r1, c1); memset(vis, 0, sizeof vis);
	vector<pair<int, int>> v1, v2;
	while(!q.empty()){
		auto [i, j] = q.front(); q.pop();
		if(vis[i][j]) continue;
		vis[i][j] = 1, v1.emplace_back(i, j);

		for(auto [a, b]: moves){
			a += i, b += j;
			if(a < 0 or a >= n or b < 0 or b >= n or v[a][b] == '1') continue;
			q.push({a, b});
		}
	}

	if(vis[r2][c2]){ cout << 0 << endl; return; }

	q.emplace(r2, c2);
	while(!q.empty()){
		auto [i, j] = q.front(); q.pop();
		if(vis[i][j]) continue;
		vis[i][j] = 2, v2.emplace_back(i, j);

		for(auto [a, b]: moves){
			a += i, b += j;
			if(a < 0 or a >= n or b < 0 or b >= n or v[a][b] == '1') continue;
			q.push({a, b});
		}
	}
	
	int ans = LINF;
	for(auto [a, b]: v1) for(auto [c, d]: v2) ans = min(ans, (c-a)*(c-a)+(d-b)*(d-b));
	cout << ans << endl;
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


