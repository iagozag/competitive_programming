#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

ll fexp(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	vector<int> v(n), k(n);
	for(auto& x: v) cin >> x;
	for(auto& x: k) cin >> x;
	for(int i = 0; i < n; i++){
		cout << fexp(2, k[i]) << endl;
	}
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
