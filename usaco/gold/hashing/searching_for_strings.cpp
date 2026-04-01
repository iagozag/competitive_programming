#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = (1ll<<61) - 1;
ll mulmod(ll a, ll b) {
	const static ll LOWER = (1ll<<30) - 1, GET31 = (1ll<<31) - 1;
	ll l1 = a&LOWER, h1 = a>>30, l2 = b&LOWER, h2 = b>>30;
	ll m = l1*h2 + l2*h1, h = h1*h2;
	ll ans = l1*l2 + (h>>1) + ((h&1)<<60) + (m>>31) + ((m&GET31)<<30) + 1;
	ans = (ans&MOD) + (ans>>61), ans = (ans&MOD) + (ans>>61);
	return ans - 1;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); 

ll uniform(ll l, ll r) {
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}
 
struct str_hash {
	static ll P;
	vector<ll> h, p;
	str_hash(string s) : h(s.size()), p(s.size()) {
		p[0] = 1, h[0] = s[0];
		for (int i = 1; i < s.size(); i++)
			p[i] = mulmod(p[i - 1], P), h[i] = (mulmod(h[i - 1], P) + s[i])%MOD;
	}
	ll operator()(int l, int r) { // retorna hash s[l...r]
		ll hash = h[r] - (l ? mulmod(h[l - 1], p[r - l + 1]) : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};
ll str_hash::P = uniform(256, MOD - 1); // l > |sigma|

void solve(){
	string s, t; cin >> s >> t; int n = s.size(), m = t.size();
	if(n > m){ cout << 0 << endl; return; }

	vector<int> x(26);
	for(int i = 0; i < n; i++) x[s[i]-'a']++;

	str_hash hash(t);
	vector<int> y(26);
	for(int j = 0; j < n; j++) y[t[j]-'a']++;

	set<int> st; 
	for(int j = 0; j+n-1 < m; j++){
		if(x == y) st.insert(hash(j, j+n-1));
		if(j+n < m) y[t[j]-'a']--, y[t[j+n]-'a']++;
	}

	cout << st.size() << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
