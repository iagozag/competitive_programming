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
	int n, t; cin >> n >> t;
	vector<int> c(n), r(n); for(auto& x: c) cin >> x;
	for(auto& x: r) cin >> x;

	int ans = -1, ma = -1;
	for(int i = 0; i < n; i++){
		if(c[i] == t and ma < r[i]) ma = r[i], ans = i;
	}

	if(ma != -1){ cout << ans+1 << endl; return; }

	t = c[0];
	ans = -1, ma = -1;
	for(int i = 0; i < n; i++){
		if(c[i] == t and ma < r[i]) ma = r[i], ans = i;
	}

	cout << ans+1 << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
