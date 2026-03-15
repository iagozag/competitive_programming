#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

int fact[60];

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

int comb(int a, int b){
	if(a < b or b == 0) return 1;
	return fact[a]*fexp(fact[b], MOD-2)%MOD*fexp(fact[a-b], MOD-2)%MOD;
}

void solve(){
	int n, zeros = 0; cin >> n;
	vector<int> v(n+1); for(auto& x: v) cin >> x, zeros += (x == 0);
	zeros -= (v[0] == 0);


	while(zeros <= v[0]){
		int mi = INF;
		for(int i = 1; i <= n; i++) if(v[i]) mi = min(mi, v[i]);

		if(zeros) mi = min(mi, v[0]/zeros);

		zeros = 0;
		for(int i = 1; i <= n; i++){
			if(v[i]) v[i] -= mi;
			else v[0] -= mi;

			zeros += (v[i] == 0);
		}
	}

	if(*max_element(v.begin()+1, v.end()) > 1){ cout << 0 << endl; return; }

	int ones = n-zeros;
	cout << comb(zeros, v[0])*fact[ones+v[0]]%MOD*fact[n-ones-v[0]]%MOD << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

	fact[0] = 1;
	for(int i = 1; i < 60; i++) fact[i] = fact[i-1]*i%MOD;

    while(ttt--) solve();

    exit(0);
}
