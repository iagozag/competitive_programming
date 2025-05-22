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
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;
	sort(v.begin(), v.end());

	vector<int> pref(n); for(int i = 0; i < n; i++) pref[i] = (i ? pref[i-1] : 0)+v[i];
	auto get_sum = [&](int l, int r) -> int{
		return pref[r]-(l ? pref[l-1] : 0);
	};

	int ans = LINF;
	for(int i = 0; i < n; i++){
		ans = min(ans, v[i]*i-(i ? get_sum(0, i-1) : 0)+get_sum(i+1, n-1)-v[i]*(n-1-i));
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
