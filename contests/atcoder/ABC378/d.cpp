#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int h, w, k;
vector<vector<int>> v;
ll ans = 0;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int i, int j, int c, set<pair<int, int>> st){
	if(c == k){ ans++; return; }

	st.insert({i, j});
	for(auto [a, b]: moves){
		int x = i+a, y = j+b;
		if(x >= 0 and x < h and y >= 0 and y < w and v[x][y] == 0 and !st.count({x, y})) dfs(x, y, c+1, st);
	}
}

void solve(){
	cin >> h >> w >> k;
	v = vector<vector<int>>(h, vector<int>(w));
	for(int i = 0; i < h; i++){
		string s; cin >> s;
		for(int j = 0; j < w; j++) if(s[j] == '#') v[i][j] = 1;
	}

	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++){
		if(v[i][j] == 0) dfs(i, j, 0, {});
	}

	cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
