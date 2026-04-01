#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+33, MOD2 = 1e9+9;

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
	int n, k; cin >> n >> k;
	vector<str_hash<MOD>> hs;
	vector<str_hash<MOD2>> hs2;
	vector<string> v(n); for(auto& s: v) cin >> s, hs.push_back(str_hash<MOD>(s)), hs2.push_back(str_hash<MOD2>(s));
	vector<int> ans(n);

	if(n*n*k < n*k*k*log2(n*k*k)){
		for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++){
			int diff = 0;
			for(int l = 0; l < k; l++) if(v[i][l] != v[j][l]) diff++;
			if(diff <= 2) ans[i] = ans[j] = 1;
		}
	} else{
		for(int j = 0; j < k; j++) for(int l = j+1; l < k; l++){
			vector<tuple<int, int, int, int>> hashes;
			for(int i = 0; i < n; i++){
				int h1 = 0, h2 = 0, h3 = 0;
				if(j) h1 = hs[i](0, j-1);
				if(j+1 < l) h2 = hs[i](j+1, l-1);
				if(l+1 < k) h3 = hs[i](l+1, k-1);

				hashes.emplace_back(h1, h2, h3, i);
			}

			sort(hashes.begin(), hashes.end());
			for(int i = 0; i < n; i++) if(i+1 < n){
				auto [h1, h2, h3, x] = hashes[i];
				auto [h4, h5, h6, y] = hashes[i+1];
				if(h1 == h4 and h2 == h5 and h3 == h6) ans[x] = ans[y] = 1;
			}
		}
	}

	for(auto x: ans) cout << x;
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

