#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

ll n;
vector<ll> v, memo;
map<ll, vector<ll>> mp;

ll dp(ll i){
	if(memo[i] != -1) return memo[i];

	ll need = 2*i+v[i]-n;
	if(i == 0 or mp[need].size() == 0) return memo[i] = i;

	for(auto j: mp[need]) memo[i] = max(memo[i], i+dp(j));

	return memo[i];
}

void solve(){
	cin >> n;
	v = vector<ll>(n), mp.clear();
	for(ll i = 0; i < n; i++){
		cin >> v[i];
		if(i+v[i] > n) mp[i+v[i]-n].emplace_back(i);
	}
	ll ans = 0; memo = vector<ll>(n, -1);
	for(ll i = 0; i < n; i++){
		if(i+v[i] == n) ans = max(ans, dp(i));
	}

	cout << n+ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
