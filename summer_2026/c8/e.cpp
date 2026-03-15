#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 4e5+10, MOD = 998244353;

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

int inv(int x){
	return fexp(x, MOD-2);
}

int fact[MAX];

int comb(int a, int b){
	return fact[a]*inv(fact[b])%MOD*inv(fact[a-b])%MOD;
}

void solve(){
	int n, m; cin >> n >> m;
	if(n < m) swap(n, m);

	cout << (((comb(n+m, n)-comb(n+m, n+1))%MOD)+MOD)%MOD << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

	fact[0] = 1;
	for(int i = 1; i < MAX; i++) fact[i] = fact[i-1]*i%MOD;

    while(ttt--) solve();

    exit(0);
}
