#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	ll n, k; cin >> n >> k;
	vector<ll> a(n), b(n); for(auto& x: a) cin >> x; for(auto& x: b) cin >> x;

	vector<ll> ans(n);
	for(int i = n-1; i >= 0; i--){
		ans[i] = min(k, a[i]/b[i]), k -= ans[i];
	}

	if(k > 0) ans = vector<ll>(n);
	for(auto x: ans) cout << x << " ";
	cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
