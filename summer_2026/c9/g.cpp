#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

int vis[1010];
vector<vector<int>> g(1010);

long double dist(long double a, long double b, long double c, long double d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

void dfs(int v){
	vis[v] = 1;
	for(auto ve: g[v]) if(!vis[ve]) dfs(ve);
}

void no(){ cout << "N" << endl; }
void yes(){ cout << "S" << endl; }

void solve(){
	int n, m, k; cin >> m >> n >> k;
	vector<tuple<int, int, int>> sensor;
	for(int i = 0; i < k; i++){
		int x, y, s; cin >> x >> y >> s;
		sensor.emplace_back(x, y, s);
	}

	// 0 - left
	// 1 - down
	// 2 - right
	// 3 - up
	
	for(int i = 0; i < k; i++){
		auto [x, y, s] = sensor[i];
		if(x-s <= 0) g[0].emplace_back(i+4), g[i+4].emplace_back(0);
		if(y+s >= n) g[1].emplace_back(i+4), g[i+4].emplace_back(1);
		if(x+s >= m) g[2].emplace_back(i+4), g[i+4].emplace_back(2);
		if(y-s <= 0) g[3].emplace_back(i+4), g[i+4].emplace_back(3);

		for(int j = i+1; j < k; j++){
			auto [x2, y2, s2] = sensor[j];
			if(dist(x, y, x2, y2) <= (long double)(s+s2)) g[i+4].emplace_back(j+4), g[j+4].emplace_back(i+4);
		}
	}

	memset(vis, 0, sizeof vis);
	dfs(0);
	if(vis[2] or vis[3]) return no();

	memset(vis, 0, sizeof vis);
	dfs(1);
	if(vis[2] or vis[3]) return no();

	yes();
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


