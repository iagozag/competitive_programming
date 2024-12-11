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
	int n, x, k; cin >> n >> x >> k;
	vector<pair<int, int>> dp(x+1);
	
	vector<vector<pair<int, int>>> v(n+1);
	for(int i = 0; i < n; i++){
		int a, b, c; cin >> a >> b >> c;
		v[c].emplace_back(a, b);
	}

	for(int i = 1; i < n; i++){
		for(auto [a, b]: v[i]){
			for(int j = x; j >= a; j--){
				auto [t, l] = dp[j-a];
				int tot = t+b+(l == i ? 0 : k);
				if(tot > dp[j].first) dp[j] = {tot, (l == i ? dp[j].second : i)};
			}
		}
	}

	int ans = 0;
	for(int i = 1; i < x+1; i++) ans = max(ans, dp[i].first);
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
