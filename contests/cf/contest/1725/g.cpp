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

	int l = 3, r = 1e18, ans = 0;
	while(l <= r){
		int m = l+(r-l)/2, tmp = 0;
		tmp += m/2+(m&1)-1;
		if(m >= 8) tmp += (m-8)/4+1;

		if(tmp < n) l = m+1;
		else ans = m, r = m-1;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
