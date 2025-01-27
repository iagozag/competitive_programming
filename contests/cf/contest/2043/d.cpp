#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void yes(int a, int b){
	cout << a << ' ' << b << endl;
}

void solve(){
	int l, r, g; cin >> l >> r >> g;
	if(l%g) l += g-(l%g);
	if(r%g) r -= r%g;

	if(l > r){ cout << "-1 -1" << endl; return; }
	
	for(int i = r-l; i >= 0; i -= g){
		int a = l, b = a+i;
		while(b <= r){
			if(__gcd(a, b) == g) return yes(a, b);
			a += g, b += g;
		}
	}

	cout << -1 << ' ' << -1 << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
