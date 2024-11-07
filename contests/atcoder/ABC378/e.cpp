#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void smod(ll& a, ll b, ll m){
	a += b, a %= m, a += m, a %= m;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<ll> v(n); for(auto& x: v) cin >> x, x %= m;

	ll ans = 0, pref = 0;
	for(int i = 0; i < n; i++){
		pref += v[i]*(n-i);
		ans += pref;
	}
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
