#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<string> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	vector<vector<char>> ans(n, vector<char>(n));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
		string c = ""; c += v[i][j], c += v[n-j-1][i], c += v[n-i-1][n-j-1], c += v[j][n-i-1];
		ans[i][j] = c[min({i+1, j+1, n-i, n-j})%4];
	}

	for(auto x: ans){ for(auto y: x) cout << y; cout << endl; }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
