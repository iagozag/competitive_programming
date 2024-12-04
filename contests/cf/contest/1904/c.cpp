#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, k; cin >> n >> k;
	vector<ll> v(n); for(auto& x: v) cin >> x;
	sort(v.begin(), v.end());
	if(k > 2){ cout << 0 << endl; return; }

	ll ans = v[0];
	for(int i = 0; i < n-1; i++) ans = min(ans, abs(v[i+1]-v[i]));

	if(k == 1){ cout << ans << endl; return; }

	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			ll num = abs(v[i]-v[j]);
			int lb = lower_bound(v.begin(), v.end(), num)-v.begin();
			if(lb >= 0 and lb < n) ans = min(ans, abs(num-v[lb]));
			if(lb-1 >= 0 and lb-1 < n) ans = min(ans, abs(num-v[lb-1]));
		}
	}
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
