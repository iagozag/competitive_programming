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
	vector<pair<int, int>> v(n);
	for(auto& [a, b]: v) cin >> a >> b;
	sort(v.begin(), v.end(), [&](pair<int, int> x, pair<int, int> y){
		auto [a1, b1] = x;
		auto [a2, b2] = y;
		return a1-b1 > a2-b2;
	});

	int l = 0, r = 1e18, ans = r;
	while(l <= r){
		int m = l+(r-l)/2;

		int hp = m; bool can = 1;
		for(int i = 0; i < n; i++){
			if(hp < v[i].first) can = 0;
			else hp -= v[i].second;
		}

		if(hp >= 0 and can) ans = m, r = m-1;
		else l = m+1;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
