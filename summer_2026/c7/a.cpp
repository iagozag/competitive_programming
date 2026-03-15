#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

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

int n;

int get_size(int idxl, int idxr){
	return idxl+n-idxr+1;
}

void solve(){
	string s; cin >> s; n = s.size();

	if(n == 1){ cout << s << endl; return; }

	string rev = s; reverse(rev.begin(), rev.end());

	str_hash<MOD> hs(s), hr(rev);

	auto test = [&](int l, int r){
		return hs(l, r) == hr(n-r-1, n-l-1);
	};

	int idxl = -1, idxr = n;
	while(idxl+1 <= idxr-1 and s[idxl+1] == s[idxr-1]) idxl++, idxr--;

	int prevl = idxl, prevr = idxr;
	for(int i = idxl+1; i < idxr; i++){
		if(test(prevl+1, i)) idxl = i;
	}
	
	for(int i = idxr-1; i > prevl; i--){
		if(test(i, prevr-1)) idxr = i;
	}

	int betl, betr;
	if(get_size(idxl, prevr) >= get_size(prevl, idxr)) betl = idxl, betr = prevr;
	else betl = prevl, betr = idxr;
	
	if(betl == betr) betr++;
	
	string ans = "";
	for(int i = 0; i <= betl; i++) ans += s[i];
	for(int i = betr; i < n; i++) ans += s[i];
	cout << ans << endl;
}

int32_t main(){
	int ttt = 1; cin >> ttt;

	while(ttt--) solve();

	exit(0);
}
