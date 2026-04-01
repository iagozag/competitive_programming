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

const int K = 40;

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x, --x;

	vector<array<int, K>> hash(n);
	for(int i = 0; i < n; i++) for(int j = 0; j < K; j++) hash[i][j] = uniform(0, 2);

	vector<int> qnt(n);
	vector<array<int, K>> pref(n);
	map<array<int, K>, int> mp; mp[pref[0]] = 1;

	int l = 0, r = 0, ans = 0;
	while(r < n){
		while(r < n and qnt[v[r]] < 3) {
			if(r) pref[r] = pref[r-1];
			for(int j = 0; j < K; j++) pref[r][j] += hash[v[r]][j], pref[r][j] %= 3;

			ans += mp[pref[r]];
			mp[pref[r]]++;
			qnt[v[r++]]++;
		}

		qnt[v[l]]--;
		if(l == 0) mp[array<int, K>()]--;
		else mp[pref[l-1]]--;
		l++;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
