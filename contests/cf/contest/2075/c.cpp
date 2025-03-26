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
	int n, m; cin >> n >> m;
	vector<int> v(m); for(int i = 0; i < m; i++){ cin >> v[i]; if(v[i] == n) v[i]--; }
	sort(v.begin(), v.end());

	vector<int> pref(m); pref[0] = v[0]; for(int i = 1; i < m; i++) pref[i] = pref[i-1]+v[i];

	int ans = 0;
	for(int i = 1; i < m; i++){
		int l = lower_bound(v.begin(), v.begin()+i, n-v[i])-v.begin(), r = i-1;
		if(l <= r) ans += 2LL*((r-l+1)+v[i]*(r-l+1)-(n*(r-l+1)-(pref[r]-(l ? pref[l-1] : 0))));
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
