#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e6+10, MOD = 998244353;

vector<int> fact(MAX), inv(MAX);

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}

	return ans;
}

int c(int a, int b){
	if(a < b) return 0;
	return fact[a]*inv[b]%MOD*inv[a-b]%MOD;
}

void summ(int& a, int b){ a += b, a %= MOD; }

void solve(){
	int x1, x2, x3; cin >> x1 >> x2 >> x3; int n = x1+x2+x3;

	fact[0] = 1, inv[0] = 1;
	for(int i = 1; i <= n; i++) fact[i] = fact[i-1]*i%MOD, inv[i] = fexp(fact[i], MOD-2);

	int ans = 0;

	// starts and ends with 1
	for(int i = 2; i <= x1; i++){
		summ(ans, c(x1-1, i-1)*c(x3-1, i-2)%MOD*c(x1+x2+x3-(2*i-2), x1+x3)%MOD);
	}

	// starts and ends with 3
	for(int i = 2; i <= x3; i++){
		summ(ans, c(x3-1, i-1)*c(x1-1, i-2)%MOD*c(x1+x2+x3-(2*i-2), x1+x3)%MOD);
	}

	// starts with 1 and ends with 3 
	for(int i = 1; i <= x1; i++){
		summ(ans, c(x1-1, i-1)*c(x3-1, i-1)%MOD*c(x1+x2+x3-(2*i-1), x1+x3)%MOD);
	}

	// starts with 3 and ends with 1
	for(int i = 1; i <= x3; i++){
		summ(ans, c(x3-1, i-1)*c(x1-1, i-1)%MOD*c(x1+x2+x3-(2*i-1), x1+x3)%MOD);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
