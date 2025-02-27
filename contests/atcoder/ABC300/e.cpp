#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

map<int, long double> memo;

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

int dp(int n){
	if(n == 1) return 1;
	if(memo.count(n)) return memo[n];

	int sum = 0;
	for(int i = 2; i <= 6; i++) if(n%i == 0) sum += dp(n/i), sum %= MOD;
	return memo[n] = sum*fexp(5, MOD-2)%MOD;
}

void solve(){
	int n; cin >> n;
	cout << dp(n) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
