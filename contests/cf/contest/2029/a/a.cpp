#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	ll l, r, k; cin >> l >> r >> k;
	ll bl = l, br = r, ans = 0;
	while(bl <= br){
		ll mid = (bl+br)>>1;
		if(mid*k <= r) bl = mid+1, ans = mid;
		else br = mid-1;
	}
	cout << max(0LL, ans-l+1) << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
