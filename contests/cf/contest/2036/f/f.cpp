#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	ll l, r, i, k; cin >> l >> r >> i >> k;
	ll m = 1<<i, ans = r-l+1;
	
	while(l%m != k) l++;
	while(r%m != k) r--;

	if(l == m){ cout << ans-1 << endl; return; }
	ans -= (r-l)/m;
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
