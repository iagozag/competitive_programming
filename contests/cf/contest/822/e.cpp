#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+33;

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
	int n, m, x;
	string s, t;
	cin >> n >> s >> m >> t >> x;

	str_hash<MOD> hs(s), ht(t);

	vector<vector<int>> dp(n+1, vector<int>(x+1));
	for(int i = 0; i < n; i++) for(int j = 0; j <= x; j++){
		int k = dp[i][j];

		int l = 1, r = min(n-i, m-k), ans = 0;
		while(l <= r){
			int mid = l+(r-l)/2;

			if(hs(i, i+mid-1) == ht(k, k+mid-1)) ans = mid, l = mid+1;
			else r = mid-1;
		}

		if(j < x) dp[i+ans][j+1] = max(dp[i+ans][j+1], dp[i][j]+ans);

		if(i < n-1) dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
		if(j < x) dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
	}

	for(int i = 0; i <= n; i++) for(int j = 0; j <= x; j++) if(dp[i][j] == m){
		cout << "YES" << endl;
		return;
	}

	cout << "NO" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
