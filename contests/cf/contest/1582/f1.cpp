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
	int n; cin >> n; n++;
	vector<int> v(n); for(int i = 1; i < n; i++) cin >> v[i];

	vector<int> dp(512, LINF); dp[0] = 0;
	for(int i = 1; i < n; i++){
		vector<pair<int, int>> ins;
		for(int j = 511; j >= 0; j--){
			if(v[i] > dp[j]) ins.emplace_back(v[i]^j, v[i]);
		}

		for(auto [a, b]: ins) dp[a] = min(dp[a], b);
	}

	vector<int> ans;
	for(int j = 0; j < 512; j++) if(dp[j] < LINF) ans.emplace_back(j);
	
	cout << ans.size() << endl;
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
