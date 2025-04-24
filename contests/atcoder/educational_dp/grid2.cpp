#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int h, w, n;
vector<int> fact(MAX);
vector<int> memo(MAX, -1);
vector<int> r(MAX), c(MAX);

int inv(int a){
	int ans = 1, b = MOD-2;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

int comb(int i, int j){
	return fact[i+j]*inv(fact[i])%MOD*inv(fact[j])%MOD;
}

int sub(int a, int b){
	a -= b;
	a %= MOD;
	a += MOD;
	a %= MOD;
	return a;
}

int dp(int i){
	if(memo[i] != -1) return memo[i];

	memo[i] = comb(r[i], c[i]);
	for(int j = 0; j < n; j++) if(i != j and r[j] <= r[i] and c[j] <= c[i]) 
		memo[i] = sub(memo[i], dp(j)*comb(r[i]-r[j], c[i]-c[j])%MOD);

	return memo[i];
}

void solve(){
	cin >> h >> w >> n;
	for(int i = 0; i < n; i++) cin >> r[i] >> c[i], r[i]--, c[i]--;
	r[n] = h-1, c[n] = w-1;

	cout << dp(n) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

	fact[0] = fact[1] = 1;
	for(int i = 2; i < MAX; i++) fact[i] = fact[i-1]*i%MOD;

    while(ttt--) solve();

    exit(0);
}
