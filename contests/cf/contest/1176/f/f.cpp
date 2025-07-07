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
	vector<vector<int>> dp(n+1, vector<int>(10, -LINF)); dp[0][0] = 0;
	for(int i = 0; i < n; i++){
		int k; cin >> k;
		for(int j = 0; j < 10; j++) dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

		vector<vector<int>> cards(3);
		for(int l = 0; l < k; l++){
			int a, b; cin >> a >> b; --a;
			cards[a].emplace_back(b);
		}
		for(int c = 0; c < 3; c++) sort(cards[c].begin(), cards[c].end(), greater<int>());

		for(int j = 0; j < 10; j++) if(dp[i][j] >= 0){
			// 1 mana
			int nj = (j+1)%10;
			if(cards[0].size()) dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+(nj == 0 ? 2 : 1)*cards[0][0]);

			// 2 mana
			nj = (j+2)%10;
			if(cards[0].size() >= 2) dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+(nj <= 1 ? 2 : 1)*cards[0][0]+cards[0][1]);

			nj = (j+1)%10;
			if(cards[1].size()) dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+(nj == 0 ? 2 : 1)*cards[1][0]);

			// 3 mana
			nj = (j+3)%10;
			if(cards[0].size() >= 3) dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+(nj <= 2 ? 2 : 1)*cards[0][0]+cards[0][1]+cards[0][2]);

			nj = (j+2)%10;
			if(cards[0].size() and cards[1].size()){
				int mi = min(cards[0][0], cards[1][0]), ma = max(cards[0][0], cards[1][0]);
				dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+(nj <= 1 ? 2 : 1)*ma + mi);
			}

			nj = (j+1)%10;
			if(cards[2].size()) dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+(nj == 0 ? 2 : 1)*cards[2][0]);
		}
	}

	int ans = 0;
	for(int j = 0; j < 10; j++) ans = max(ans, dp[n][j]);
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
