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
	int n; cin >> n; int ans = 0;
	vector<int> v(n); for(auto& x: v) cin >> x, ans += x;

	for(int i = n-1; i > 0; i--){
		vector<int> nv(i);
		int sum = 0;
		for(int j = 0; j < i; j++) nv[j] = v[j+1]-v[j], sum += nv[j];
		ans = max({ans, sum, -sum}), v = nv;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
