#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int query(int i){
	cout << "? " << i << endl;
	int q; cin >> q;
	return q;
}

void solve(){
	int n; cin >> n;

	int l = 1, r = n, ans = 1;
	while(l <= r){
		int m = l+(r-l)/2;

		int q = query(m);
		if(q) ans = m-1, r = m-1;
		else l = m+1;
	}

	cout << "! " << ans << endl;
}

int32_t main(){ // _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
