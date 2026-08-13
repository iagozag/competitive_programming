#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 988931033;

int fact[2*MAX];

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

int inv(int x){ return fexp(x, MOD-2); }

int f(int n, int m){
	return fact[n+m]*inv(fact[n])%MOD*inv(fact[m])%MOD;
}

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;
	v.emplace_back(1);

	int ans = 0;
	for(int i = 0; i < n+1; i++){
		ans += f(i+1, v[i]-1);
		ans %= MOD;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

	fact[0] = 1;
	for(int i = 1; i < 2*MAX; i++) fact[i] = fact[i-1]*i%MOD;

    while(ttt--) solve();

    exit(0);
}
