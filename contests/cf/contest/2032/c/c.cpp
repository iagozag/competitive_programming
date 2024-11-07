#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<ll> v(n); for(auto& x: v) cin >> x;
	sort(v.begin(), v.end());

	int ans = n-2; int l = 0, r = 2;
	while(r < n){
		while(r-l >= 2 and v[l]+v[l+1] <= v[r]) l++;
		ans = min(ans, n-(r-l+1)), r++;
	}
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
