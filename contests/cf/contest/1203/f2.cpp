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
	int n, r; cin >> n >> r;
	vector<pair<int, int>> v(n);
	for(auto& [a, b]: v) cin >> a >> b;
	sort(v.begin(), v.end(), [&](pair<int, int> e1, pair<int, int> e2){
		auto [a1, b1] = e1;
		auto [a2, b2] = e2;
		if(b1 > 0 and b2 < 0) return true;
		if(b1 < 0 and b2 > 0) return false;
		if(b1 > 0 and b2 > 0) return a1 < a2;
		return a1+b1 > a2+b2;
	});

	vector<int> dp(n+1, -LINF); dp[0] = r;
	for(int i = 0; i < n; i++){
		auto [a, b] = v[i];
		for(int j = n-1; j >= 0; j--) if(dp[j] >= a and dp[j]+b >= 0) dp[j+1] = max(dp[j+1], dp[j]+b);
	}

	int ans = 0;
	for(int i = 0; i <= n; i++) if(dp[i] != -LINF) ans = i;
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
