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
	int k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
	int ans = 0, prev = k; k = 1;
	while(k < 1e10){
		int l = l1, r = r1, x = -1, y = -1;
		while(l <= r){
			int mid = l+(r-l)/2;
			if(k*mid >= l2) x = mid, r = mid-1;
			else l = mid+1;
		}

		l = l1, r = r1;
		while(l <= r){
			int mid = l+(r-l)/2;
			if(k*mid <= r2) y = mid, l = mid+1;
			else r = mid-1;
		}

		k *= prev, ans += (x != -1 and y != -1 ? y-x+1 : 0);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
