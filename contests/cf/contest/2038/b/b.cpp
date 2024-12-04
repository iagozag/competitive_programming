#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

bool good(ll x, ll ops, vector<ll> v){
	ll n = v.size(); bool can = true;
	while(ops > 0 and can){
		can = false;
		for(ll i = 0; i < n; i++) if(v[i] > x) 
			ops -= (v[i]-x+1)/2, v[(i+1)%n] += (v[i]-x+1)/2, v[i] = ((x&1) == (v[i]&1) ? x : x-1), can = true;
	}

	for(ll i = 0; i < n; i++) if(v[i] != x) return false;
	return true;
}

void solve(){
	ll n; cin >> n; ll sum = 0;
	vector<ll> v(n); for(auto& x: v) cin >> x, sum += x;

	ll l = 0, r = 1e9, ans = -1;
	while(l <= r){
		ll m = l+(r-l)/2;
		if(good(m, sum-m*n, v)) l = m+1, ans = m;
		else r = m-1;
	}

	if(ans == -1) cout << -1 << endl;
	else cout << sum-ans*n << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
