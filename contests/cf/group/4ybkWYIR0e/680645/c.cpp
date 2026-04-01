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
	int n, b, l; cin >> n >> b >> l;
	vector<int> val(n); for(auto& x: val) cin >> x;

	int ans = -LINF;
	queue<tuple<int, int>> q; q.push({1, 1}); vector<int> dp(n+1); dp[1] = val[0];
	while(!q.empty()){
		auto [v, pot] = q.front(); q.pop();

		for(int j = 1; j <= b; j++){
			int ve = v+j*pot;
			if(ve <= n){
				dp[ve] = dp[v]+val[ve-1];
				q.push({ve, pot*b});
			}
			else ans = max(ans, dp[v]);
		}
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
