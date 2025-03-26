#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;

	vector<int> comb(1<<m);
	for(int i = 0; i < (1<<m); i++){
		comb[i] = (1<<30)-1;
		for(int j = 0; j < m; j++) if(i&(1<<j)) comb[i] &= b[j];
	}

	vector<int> diff;
	for(int i = 0; i < n; i++){
		vector<int> mi(m+1, LINF);
		for(int j = 0; j < (1<<m); j++) mi[__builtin_popcount(j)] = min(mi[__builtin_popcount(j)], a[i]&comb[j]);

		for(int j = 0; j < m; j++) diff.emplace_back(mi[j]-mi[j+1]);
	}

	sort(diff.begin(), diff.end(), greater<int>());

	int ans = 0;
	for(auto x: a) ans += x;
	for(int i = 0; i < k; i++) ans -= diff[i];

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
