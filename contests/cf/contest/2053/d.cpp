#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD, b >>= 1;
	}
	return ans;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<int> a(n), b(n), pa, pb;
	for(auto& x: a) cin >> x, pa.emplace_back(x);
	for(auto& x: b) cin >> x, pb.emplace_back(x);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int ans = 1;
	for(int i = 0; i < n; i++){
		if(a[i] < b[i]) ans *= a[i];
		else ans *= b[i];
		ans %= MOD;
	}
	cout << ans << ' ';

	for(int i = 0; i < m; i++){
		int op, idx; cin >> op >> idx; op--, idx--;
		if(!op){
			int ub = upper_bound(a.begin(), a.end(), pa[idx])-a.begin(); ub--;
			pa[idx]++;

			if(a[ub] < b[ub]) ans *= fexp(a[ub], MOD-2), ans %= MOD, a[ub]++, ans *= a[ub], ans %= MOD;
			else a[ub]++;
		} else{
			int ub = upper_bound(b.begin(), b.end(), pb[idx])-b.begin(); ub--;
			pb[idx]++;
			if(b[ub] < a[ub]) ans *= fexp(b[ub], MOD-2), ans %= MOD, b[ub]++, ans *= b[ub], ans %= MOD;
			else b[ub]++;
		}

		cout << ans << ' ';
	}
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
