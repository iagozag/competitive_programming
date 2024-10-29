#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	ll n, m; cin >> n >> m;
	vector<pair<int, int>> v(n); for(auto& x: v) cin >> x.first >> x.second;
	sort(v.begin(), v.end());
	
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; i++) a[i] = v[i].first, b[i] = v[i].second;

	ll ans = m*(m+1)/2LL-a[0]*(m-b[0]+1), l = a[0], r = b[0];
	for(int i = 1; i < n; i++){
		if(a[i] > r) ans -= (a[i]-r+1)*(m-b[i]+1);
		else ans -= (a[i]-l)*(m-b[i]+1);
		l = a[i], r = b[i];
	}
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
