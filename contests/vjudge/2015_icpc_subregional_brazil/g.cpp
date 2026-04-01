#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 200, MOD = 1e9+7;

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		b >>= 1, a = a*a%MOD;
	}
	return ans;
}

int inv(int x){ return fexp(x, MOD-2); }

int fact[MAX];
int comb(int n, int r){
	return fact[n]*inv(fact[n-r])%MOD*inv(fact[r])%MOD;
}

int N, K;
vector<vector<int>> memo;
int dp(int n, int p){
	if(n == 0) return 1;
	if(p >= N) return 0;

	if(memo[n][p] != -1) return memo[n][p];

	memo[n][p] = 0;
	for(int i = 0; i <= min(n, K-1); i++){
		memo[n][p] += comb(n, i)*dp(n-i, p+1)%MOD;
	}
	memo[n][p] %= MOD;
	return memo[n][p];
}

void solve(){
	while(cin >> N >> K){
		if(N == 1){ cout << 1 << endl; continue; }

		memo = vector<vector<int>>(N-1, vector<int>(N, -1));
		cout << dp(N-2, 0) << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

	fact[0] = 1;
	for(int i = 1; i < MAX; i++) fact[i] = fact[i-1]*i%MOD;

    while(ttt--) solve();

    exit(0);
}
