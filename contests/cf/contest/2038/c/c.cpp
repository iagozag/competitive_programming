#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	ll n; cin >> n;
	map<ll, ll> mp; for(int i = 0; i < n; i++){ ll a; cin >> a; mp[a]++; }

	vector<ll> v;
	for(auto& [a, b]: mp){
		while(b >= 2) v.emplace_back(a), v.emplace_back(a), b -= 2;
	}
	if(v.size() < 8){ cout << "NO" << endl; return; }
	v.erase(v.begin()+4, v.end()-4);

	vector<ll> ans; ll ma = -1;
	do{
		if(v[0] == v[2] and v[1] == v[5] and v[4] == v[6] and v[3] == v[7] and ma < 1LL*abs(v[0]-v[4])*abs(v[1]-v[3])) ma = 1LL*abs(v[0]-v[4])*abs(v[1]-v[3]), ans = v;
	} while(next_permutation(v.begin(), v.end()));

	cout << "YES" << endl;
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
