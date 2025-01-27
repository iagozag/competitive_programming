#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m, x, y; cin >> n >> m >> x >> y; --x, --y;
	vector<string> v(n); for(auto& l: v) cin >> l;
	string t; cin >> t;
	
	vector<vector<int>> vis(n, vector<int>(m));
	for(int i = 0; i < (int)t.size(); i++){
		if(t[i] == 'U' and v[x-1][y] != '#') x--;
		else if(t[i] == 'D' and v[x+1][y] != '#') x++;
		else if(t[i] == 'L' and v[x][y-1] != '#') y--;
		else if(t[i] == 'R' and v[x][y+1] != '#') y++;

		if(v[x][y] != '.' and v[x][y] != '#') vis[x][y] = 1;
	}
	int ans = 0;
	for(auto c: vis) for(auto l: c) ans += l;
	cout << x+1 << ' ' << y+1 << ' ' << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
