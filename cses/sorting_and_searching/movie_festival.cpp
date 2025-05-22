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
	vector<pair<int, int>> v(n); for(auto& [a, b]: v) cin >> b >> a;
	sort(v.begin(), v.end()); for(auto& [a, b]: v) swap(a, b);

	int r = 0, ans = 0;
	for(int i = 0; i < n; i++){
		if(v[i].first >= r) ans++, r = v[i].second;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
