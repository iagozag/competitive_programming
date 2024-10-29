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
	vector<vector<int>> v(n, vector<int>(n)); for(auto& x: v) for(auto& y: x) cin >> y;

	vector<vector<int>> mat(n+1, vector<int>(n+1, INF)); mat[0][0] = 1;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
		mat[i][j] = abs(i-(n-1))+abs(j);	
	}

	ll ans = 0; 
	map<int, int> mp;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) mp[mat[i][j]] = min(mp[mat[i][j]], v[i][j]);
	for(auto& x: mp) if(x.second < 0) ans += -x.second;
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
