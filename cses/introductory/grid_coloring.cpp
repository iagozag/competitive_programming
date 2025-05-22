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
	int n, m; cin >> n >> m;
	vector<string> v(n), ans(n); for(auto& x: v) cin >> x;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i&1) ans[i] += (j&1 ? 'A' : 'B');
			else ans[i] += (j&1 ? 'B' : 'A');
		}
	}

	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(v[i][j] == ans[i][j]){
		ans[i][j] = ((ans[i][j] == 'A') ? 'C' : 'D');
	}

	for(auto x: ans) cout << x << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
