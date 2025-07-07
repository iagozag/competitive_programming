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
	vector<int> v(n); for(auto& x: v) cin >> x;

	int ans = n*(n-1)*(n-2)/6;

	// 2 red
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n-1; j++){
			auto ub = upper_bound(v.begin(), v.end(), v.back()-v[i]-v[j]);
			int lb = lower_bound(ub, v.end(), v[i]+v[j])-v.begin();
			ans -= n-lb;
		}
	}

	// last blue, 3 red
	for(int i = 2; i < n-1; i++){
		for(int j = 1; j < i; j++){
			int less = v.back()-v[i]-v[j];
			int ub = upper_bound(v.begin(), v.begin()+j, less)-v.begin();
			ans -= ub;
		}
	}
	
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
