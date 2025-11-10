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
	int n, x; cin >> n >> x;
	vector<int> v(n); for(auto& y: v) cin >> y;

	sort(v.begin(), v.end());

	int l = 0, r = n-1, sum = 0, ans = 0;
	vector<int> vans;
	while(l <= r){
		while(l <= r and sum+v[r] >= x) ans += v[r], vans.emplace_back(v[r]), sum += v[r--], sum %= x;

		if(l > r) break;
		
		sum += v[l];
		vans.emplace_back(v[l++]);
	}

	cout << ans << endl;
	for(auto y: vans) cout << y << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
