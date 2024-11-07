#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<ll> v(n); for(auto& x: v) cin >> x;

	ll l = 1, r = 1e18, ans = r;
	while(l <= r){
		ll m = l+(r-l)/2;
		
		int need = 0;
		for(int i = 0; i < n; i++){
			if(i+1 < n and v[i+1]-v[i] <= m) i++;
			else need++;
		}

		if(need <= 1) ans = m, r = m-1;
		else l = m+1;
	}
	
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
