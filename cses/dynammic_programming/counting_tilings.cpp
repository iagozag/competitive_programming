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
	int a, b; cin >> a >> b;
	vector<vector<int>> dp(m, (1<<n));

	for(int i = 0; i < (1<<n); i++){
		int can = 1, j = 0;
		while(j < n){
			while(j < n and !((i>>j)&1)) j++;

			int last = j;
			while(j < n and ((i>>j)&1)) j++;
			if((j-last)&1) can = 0;
		}

		dp[0][i] = can;
	}

	bool can[1<<n][1<<n];

	for(int j = 0; j < (1<<n); j++){
		for(int k = 0; k < (1<<n); k++){
			can[j][k] = 1;
			for(int i = 0; i < n; i++){
				int x = (1<<i)&j, y = (1<<i)&k;
				if(x == 0 and y == 0) can[j][k] = 0;
			}
		}
	}

	for(int i = 1; i < m-1; i++){
		for(int j = 0; j < (1<<n); j++){
			for(int k = 0; k < (1<<n); k++){
				
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < (1<<n); i++) ans += dp.back()[i], ans %= MOD;

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
