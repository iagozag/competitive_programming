#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 3e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+9;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD> struct str_hash {
	static int P;
	vector<ll> h, p;
	str_hash(string s) : h(s.size()), p(s.size()) {
		p[0] = 1, h[0] = s[0];
		for (int i = 1; i < s.size(); i++)
			p[i] = p[i - 1]*P%MOD, h[i] = (h[i - 1]*P + s[i])%MOD;
	}
	ll operator()(int l, int r) { // retorna hash s[l...r]
		ll hash = h[r] - (l ? h[l - 1]*p[r - l + 1]%MOD : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(256, MOD - 1); // l > |sigma|

void solve(){
	string s; cin >> s; int n = s.size();
	for(int i = 0; i < n; i++){
		s[i] = tolower(s[i]);
	}
	str_hash<MOD> hash(s);

	int l = 1, r = n, ans = r, idx = 0;
	while(l <= r){
		int m = l+(r-l)/2;

		map<int, int> mp;
		for(int i = 0; i+m-1 < n; i++){
			mp[hash(i, i+m-1)]++;
		}

		int can = -1;
		for(int i = 0; i+m-1 < n; i++){
			if(mp[hash(i, i+m-1)] == 1){ can = i; break; }
		}

		if(can == -1) l = m+1;
		else idx = can, ans = m, r = m-1;
	}

	for(int i = idx; i < idx+ans; i++) cout << (char)toupper(s[i]);
	cout << endl;
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


