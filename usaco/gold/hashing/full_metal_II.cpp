#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+9;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD> struct str_hash {
	static int P;
	int n;
	vector<ll> h, p;
	str_hash(string s) : n(s.size()), h(s.size()), p(s.size()) {
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
	int n; cin >> n;
	vector<str_hash<MOD>> v(n, str_hash<MOD>("."));
	for(auto& h: v){
		string s; cin >> s;
		h = str_hash<MOD>(s);
	}

	vector<str_hash<MOD>> v2; vector<bool> subs(n);
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(i != j and v[j].n <= v[i].n){
		for(int k = 0; k <= v[i].n-v[j].n; k++)
			if(v[i](k, k+v[j].n-1) == v[j](0, v[j].n-1)) subs[j] = 1;
	}

	for(int i = 0; i < n; i++) if(!subs[i]) v2.push_back(v[i]);
	v = v2, n = v.size();

	vector<vector<int>> cmp(n, vector<int>(n, LINF));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(i != j){
		cmp[i][j] = v[j].n;
		for(int k = 1; k <= min(v[i].n, v[j].n); k++)
			if(v[i](v[i].n-k, v[i].n-1) == v[j](0, k-1)) cmp[i][j] = min(cmp[i][j], v[j].n-k);
	}

	// for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cout << cmp[i][j] << " \n"[j==n-1];

	vector<vector<int>> dp(1<<n, vector<int>(n, LINF));
	for(int i = 0; i < n; i++) dp[1<<i][i] = v[i].n;

	for(int i = 0; i < (1<<n); i++){
		for(int j = 0; j < n; j++) if(i&(1<<j)){
			for(int k = 0; k < n; k++) if(!(i&(1<<k)))
				dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k], dp[i][j]+cmp[j][k]);
		}
	}

	int ans = LINF;
	for(int i = 0; i < n; i++) ans = min(ans, dp[(1<<n)-1][i]);
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
