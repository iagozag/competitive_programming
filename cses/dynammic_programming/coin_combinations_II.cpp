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
	int n, x; cin >> n >> x;
	vector<int> coins(n); for(auto& c: coins) cin >> c;
	vector<int> dp(x+1, 0); dp[0] = 1;

	for(auto c: coins){
		for(int i = 1; i <= x; i++){
			 if(i-c >= 0) dp[i] += dp[i-c], dp[i] %= MOD;
		}
	}

	cout << dp[x] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
