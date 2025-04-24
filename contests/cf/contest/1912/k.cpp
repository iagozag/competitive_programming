#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

int n;
vector<int> v;

int dp[MAX][3][3][3]; 

void sum(int& a, int b){
	a %= MOD, b %= MOD;
	a += b, a %= MOD;
}

void sub(int& a, int b){
	a %= MOD, b %= MOD;
	a -= b, a %= MOD, a += MOD, a %= MOD;
}

void solve(){
	cin >> n;
	v.resize(n); for(auto& x: v) cin >> x, x &= 1;

	memset(dp, 0, sizeof dp);
	dp[0][2][2][2] = 1;
	for(int i = 0; i < n; i++){
		sum(dp[i+1][2][2][2], dp[i][2][2][2]);
		sum(dp[i+1][v[i]][2][2], dp[i][2][2][2]);

		for(int j = 0; j < 2; j++){
			sum(dp[i+1][j][2][2], dp[i][j][2][2]);
			sum(dp[i+1][j][v[i]][2], dp[i][j][2][2]);

			for(int k = 0; k < 2; k++){
				sum(dp[i+1][j][k][2], dp[i][j][k][2]);
				sum(dp[i+1][j][k][v[i]], dp[i][j][k][2]);

				for(int l = 0; l < 2; l++){
					if((j+k+l)%2) dp[i][j][k][l] = 0;

					sum(dp[i+1][j][k][l], dp[i][j][k][l]);
					sum(dp[i+1][k][l][v[i]], dp[i][j][k][l]);
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) 
		if((i+j+k)%2 == 0) sum(ans, dp[n][i][j][k]);

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
