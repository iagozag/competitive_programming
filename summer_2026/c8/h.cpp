#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

int n, m;
vector<vector<int>> v, memo;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

int dp(int i, int j){
	if(memo[i][j] != -1) return memo[i][j];

	memo[i][j] = 0;
	for(auto [a, b]: moves){
		a += i, b += j;
		if(a < 0 or a >= n or b < 0 or b >= m or v[a][b] != v[i][j]+1) continue;
		memo[i][j] = max(memo[i][j], dp(a, b));
	}

	return memo[i][j] = memo[i][j]+1;
}

void solve(){
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m)), memo = vector<vector<int>>(n, vector<int>(m, -1));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){ char c; cin >> c; v[i][j] = (int)(c-'A'); }

	int ma = 0; 
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) ma = max(ma, dp(i, j));
	cout << ma << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


