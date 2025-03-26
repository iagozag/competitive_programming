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
	int n; cin >> n;
	vector<pair<int, int>> v(n); for(auto& [a, b]: v) cin >> a >> b;
	sort(v.begin(), v.end());
	vector<int> nv; for(auto [a, b]: v) nv.emplace_back(b);
	reverse(nv.begin(), nv.end());

	vector<int> dp(n+1, LINF); dp[0] = -LINF;
	for(int i = 0; i < n; i++){
		int ub = upper_bound(dp.begin(), dp.end(), nv[i])-dp.begin();
		dp[ub] = nv[i];
	}

	int ans = 0;
	for(int i = 0; i < n+1; i++) if(dp[i] != LINF) ans = i;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
