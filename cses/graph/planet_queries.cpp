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
	int n, q; cin >> n >> q;
	int dp[n][32];
	for(int i = 0; i < n; i++) cin >> dp[i][0], dp[i][0]--;

	for(int j = 1; j < 32; j++)
		for(int i = 0; i < n; i++)
		 dp[i][j] = dp[dp[i][j-1]][j-1];

	for(int i = 0; i < q; i++){
		int v, k; cin >> v >> k; --v;

		int ans = v;
		for(int j = 0; j < 32; j++) if((k>>j)&1LL) ans = dp[ans][j];
		cout << ans+1 << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
