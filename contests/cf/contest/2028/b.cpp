#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	ll n, a, b; cin >> n >> a >> b;
	if(a == 0 and b == 0){
		if(n == 1) cout << 0 << endl;
		else if(n == 2) cout << 1 << endl;
		else cout << -1 << endl;
	}
	else if(b >= n) cout << n << endl;
	else if(a == 0){
		if(b < n-2) cout << -1 << endl;
		else cout << n-1 << endl;
	}
	else {
		ll l = 0, r = 1, idx = 0;
		while(a*r < n-b) r <<= 1;

		while(l <= r){
			ll m = l+(r-l)/2LL;
			if(a*m < n-b) idx = m, l = m+1;
			else r = m-1;
		}

		cout << n-(idx+1LL) << endl;	
	}
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
