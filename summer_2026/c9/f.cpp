#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<int> v;

bool good(int days, int h){
	int even = days/2, odd = (days+1)/2;
	for(int i = 0; i < n; i++){
		int aux = v[i];
		int mi = min(even, (h-aux)/2);
		even -= mi, aux += mi*2;

		mi = min(odd, h-aux);
		odd -= mi, aux += mi;

		if(aux != h) return false;
	}

	return true;
}

void solve(){
	cin >> n;
	v = vector<int>(n); int ma = 0;
	for(auto& x: v) cin >> x, ma = max(ma, x);

	int l = 0, r = 1e18, ans = r;
	while(l <= r){
		int mid = l+(r-l)/2;

		if(good(mid, ma) or good(mid, ma+1)) ans = mid, r = mid-1;
		else l = mid+1;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
