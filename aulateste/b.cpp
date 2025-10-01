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
	int mat[16][16];
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> mat[i][j];

	int sums[1<<16]; memset(sums, 0, sizeof sums);
	for(int i = 0; i < (1<<n); i++) for(int j = 0; j < n; j++) for(int k = j+1; k < n; k++)
		if((i&(1<<j)) and (i&(1<<k))) sums[i] += mat[j][k];

	int dp[1<<16]; memset(dp, 0, sizeof dp);
	for(int i = 0; i < (1<<n); i++){
		for(int j = i; j; j = (j-1)&i) {
			dp[i] = max(dp[i], sums[j]+dp[i-j]);
		}
	}

	cout << dp[(1<<n)-1] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
