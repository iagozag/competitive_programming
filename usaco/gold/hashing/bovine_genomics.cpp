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
	int n, m; cin >> n >> m;
	vector<str_hash<MOD>> a(n, str_hash<MOD>(" ")), b(n, str_hash<MOD>(" "));
	for(int i = 0; i < n; i++){ string s; cin >> s; a[i] = str_hash<MOD>(s); }
	for(int i = 0; i < n; i++){ string s; cin >> s; b[i] = str_hash<MOD>(s); }

	int l = 1, r = m, ans = r;
	while(l <= r){
		int mid = l+(r-l)/2;

		int can = 0;
		for(int k = 0; k <= m-mid; k++){
			can = 1;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(a[i](k, k+mid-1) == b[j](k, k+mid-1)){ can = 0; break; }
				}
			}
			if(can) break;
		}

		if(can) ans = mid, r = mid-1;
		else l = mid+1;
	}

	cout << ans << endl;
}

int32_t main(){ _
	if (fopen("cownomics.in", "r")) {
		freopen("cownomics.in", "r", stdin);
		freopen("cownomics.out", "w", stdout);
	}
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
