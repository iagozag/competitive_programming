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
	int a, b; cin >> a >> b;
	
	int l = 0, r = 1e5, ans = 0;
	while(l <= r){
		int m = l+(r-l)/2;
		
		int ta = a, tb = b;
		for(int k = m; k >= 1; k--){
			if(ta < tb) swap(ta, tb);
			ta -= k;
		}
		if(ta >= 0 and tb >= 0) ans = m, l = m+1;
		else r = m-1;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
