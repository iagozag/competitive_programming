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
	vector<pair<int, int>> v(n); for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
	
	if(n == 1){ cout << -1 << endl; return; }
	
	long double ans = -INF;
	for(int i = 0; i < n-1; i++){

		// y = ax+b
		// y1 = ax1+b -> b = y1-ax1
		// y2 = ax2+b -> y2 = ax2+y1-ax1 -> y2-y1 = a(x2-x1);

		long double x1 = v[i].first, y1 = v[i].second, x2 = v[i+1].first, y2 = v[i+1].second;
		long double a = (y2-y1)/(x2-x1), b = y1-a*x1;

		ans = max(ans, b);
	}

	if(ans < 0) cout << -1 << endl;
	else cout << fixed << setprecision(20) << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
