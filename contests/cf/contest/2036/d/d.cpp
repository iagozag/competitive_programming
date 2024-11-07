#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

string need = "1543";
int n, m; ll ans;
vector<string> v;

void solve(){
	cin >> n >> m; ans = 0;
	v = vector<string>(n);
	for(auto& x: v) cin >> x;

	vector<vector<int>> layer(n, vector<int>(m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) layer[i][j] = min({i, j, n-i-1, m-j-1});
	for(int l = 0; l < min(n/2, m/2); l++){
		int i = l, j = l; string tmp = ""; tmp += v[i][j];
		while(j+1 < m and layer[i][j+1] == layer[i][j]) j++, tmp += v[i][j];
		while(i+1 < n and layer[i+1][j] == layer[i][j]) i++, tmp += v[i][j];
		while(j-1 >= 0 and layer[i][j-1] == layer[i][j]) j--, tmp += v[i][j];
		while(i-1 >= 0 and layer[i-1][j] == layer[i][j]) i--, tmp += v[i][j];
		tmp.pop_back();

		for(int k = 0; k < tmp.size(); k++){
			string can = "";
			for(int p = k; p < k+4; p++) can += tmp[p%tmp.size()];
			if(can == need) ans++;
		}
	}

	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
