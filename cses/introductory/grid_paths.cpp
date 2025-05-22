#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

string s;
vector<int> v(48, -1);
vector<vector<int>> vis(7, vector<int>(7));

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int f(int i, int j, int k){
	if(i == 6 and j == 0) return k == 48

	vis[i][j] = 1;

	int ans = 0;

	if(v[k] == -1){
		for(auto [a, b]: moves){
			a += i, b += j;
			if(a < 0 or a >= 7 or b < 0 or b >= 7 or vis[a][b]) continue;
			ans += f(a, b, k+1);
		}
	} else{
		auto [a, b] = moves[v[k]];
		a += i, b += j;
		if(a < 0 or a >= 7 or b < 0 or b >= 7 or vis[a][b]) ans = 0;
		else ans = f(a, b, k+1);
	}

	vis[i][j] = 0;
	return ans;
}

void solve(){
	cin >> s;
	for(int i = 0; i < 48; i++){
		if(s[i] == 'U') v[i] = 0;
		else if(s[i] == 'D') v[i] = 1;
		else if(s[i] == 'L') v[i] = 2;
		else v[i] = 3;
	}

	cout << f(0, 0, 0) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
