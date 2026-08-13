#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5e5+10, MOD = 998244353;

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

int inv(int x){ return fexp(x, MOD-2); }

void solve(){
	int n; cin >> n;
	vector<int> a(n), prefl(n), prefr(n), pref(n); for(auto& x: a) cin >> x;
	for(int i = 0; i < n; i++){
		pref[i] = (i ? pref[i-1] : 0) + a[i];
		pref[i] %= MOD;
		prefl[i] = (i ? prefl[i-1] : 0) + a[i]*(i+1);
		prefl[i] %= MOD;
	}
	for(int i = n-1; i >= 0; i--){
		prefr[i] = (i < n-1 ? prefr[i+1] : 0) + a[i]*(n-i);
		prefr[i] %= MOD;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		int sum = 0, fl = i-1, fr = n-i;

		if(fl < fr){
			sum = (prefl[fl]+prefr[fr])%MOD;
			int l = fl+1, r = fr-1;
			if(l <= r) sum += (pref[r]-pref[l-1])*i%MOD;
		} else{
			sum = (fr ? prefl[fr-1] : 0) + (fl+1 < n ? prefr[fl+1] : 0) + (pref[fl]-(fr ? pref[fr-1] : 0))*(fr+1);
		}

		sum %= MOD, sum += MOD, sum %= MOD;
		ans += sum*inv(i)%MOD, ans %= MOD;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
