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
	vector<int> v; 
	int ma = 0, ans = 0;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x > ma) ans++, ma = x;
		else v.emplace_back(x);
	}
	n = v.size();

	vector<int> dp(n+1, INF); dp[0] = -1;
	for(int i = 0; i < n; i++){
		int ub = upper_bound(dp.begin(), dp.end(), v[i])-dp.begin();
		dp[ub] = v[i];
	}

	ma = 0;
	for(int i = 0; i < n+1; i++) if(dp[i] != INF) ma = i;
	cout << ans+ma << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
