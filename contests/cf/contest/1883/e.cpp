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
	vector<ll> exp(n);
	for(int i = 1; i < n; i++){
		ll l = v[i], cntl = 0;
		while(l < v[i-1]) l <<= 1, cntl++;

		ll r = v[i-1], cntr = 0;
		while(r < v[i]) r <<= 1, cntr++;

		if(v[i] >= v[i-1]) exp[i] = max(0LL, exp[i-1]-cntr+(r > v[i]));
		else exp[i] = exp[i-1]+cntl;
	}
	ll sum = 0;
	for(int i = 0; i < n; i++) sum += exp[i];
	cout << sum << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
