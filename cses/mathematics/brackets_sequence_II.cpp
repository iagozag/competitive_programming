#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e6+10, MOD = 1e9+7;

int fact[MAX];

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

int inv(int x){ return fexp(x, MOD-2); }

int c_n_m(int n, int m){
	if(n < 0) return 0;
	return fact[n+m]*inv(fact[n])%MOD*inv(fact[m])%MOD;
}

void solve(){
	int n; cin >> n;
	if(n&1){ cout << 0 << endl; return; }
	n /= 2;

	string s; cin >> s;
	int x = n, y = n;
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] == '(') x--;
		else y--;

		if(x > y or x < 0){ cout << 0 << endl; return; }
	}

	int ans = c_n_m(x, y)-c_n_m(x-1, y+1);
	ans %= MOD, ans += MOD, ans %= MOD;

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

	fact[0] = 1;
	for(int i = 1; i < MAX; i++) fact[i] = fact[i-1]*i, fact[i] %= MOD;

    while(ttt--) solve();

    exit(0);
}
