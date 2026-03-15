#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD> struct str_hash{
	static int P;
	vector<int> h, p;
	str_hash(string s): h(s.size()), p(s.size()){
		if(!s.size()) h.resize(1), p.resize(1);
		p[0] = 1, h[0] = s[0];
		for(int i = 1; i < s.size(); i++)
			p[i] = p[i-1]*P%MOD, h[i] = (h[i-1]*P+s[i])%MOD;
	}
	ll operator()(int l, int r){
		ll hash = h[r]-(l ? h[l-1]*p[r-l+1]%MOD : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};

template<int MOD> int str_hash<MOD>::P = uniform(256, MOD-1);

void solve(){
	int n, p, s; cin >> n >> p >> s;
	
	set<int> st;
	for(int i = 0; i < n; i++){
		string a; cin >> a; int sz = a.size();

		string na = "";
		if(p+s < sz){
			for(int j = 0; j < p; j++) na += a[j];
			string ord = "";
			for(int j = p; j < sz-s; j++) ord += a[j];
			sort(ord.begin(), ord.end());
			na += ord;
			for(int j = sz-s; j < sz; j++) na += a[j];
		} else na = a;

		str_hash<MOD> hs(na);
		st.insert(hs(0, sz-1));
	}

	int m; cin >> m; bool can = 1;
	for(int i = 0; i < m; i++){
		string a; cin >> a; int sz = a.size();
		string na = "";
		if(p+s < sz){
			for(int j = 0; j < p; j++) na += a[j];
			string ord = "";
			for(int j = p; j < sz-s; j++) ord += a[j];
			sort(ord.begin(), ord.end());
			na += ord;
			for(int j = sz-s; j < sz; j++) na += a[j];
		} else na = a;

		str_hash<MOD> hs(na);
		if(!st.count(hs(0, sz-1))) can = false;
	}

	if(can) cout << "sim" << endl;
	else cout << "nao" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
