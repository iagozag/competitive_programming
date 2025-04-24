#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	vector<vector<int>> ov(n, vector<int>(m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		char x; cin >> x; ov[i][j] = (x == 'B');
	}

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		for(auto [a, b]: moves){
			a += i, b += j;
			if(a < 0 or a >= n or b < 0 or b >= m) continue;
			v[a][b]++, v[a][b] %= 2;
		}
	}

	cout << 1 << endl;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		cout << (ov[i][j] == v[i][j] ? '2' : '3');
		if(j == m-1) cout << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
