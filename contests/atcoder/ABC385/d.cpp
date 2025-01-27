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
	int n, m, x, y; cin >> n >> m >> x >> y;
	set<pair<int, int>> hr, hc; for(int i = 0; i < n; i++){ int a, b; cin >> a >> b; hr.insert({b, a}), hc.insert({a, b}); }
	int ans = 0;
	for(int i = 0; i < m; i++){
		char c; int a; cin >> c >> a;
		if(c == 'U'){
			auto lb = hc.lower_bound({x, y});
			while(lb != hc.end() and (*lb).first == x and (*lb).second <= y+a) ans++, hr.erase({(*lb).second, (*lb).first}), hc.erase(lb++);
			y += a;
		}
		else if(c == 'D'){
			auto lb = hc.lower_bound({x, y-a});
			while(lb != hc.end() and (*lb).first == x and (*lb).second <= y) ans++, hr.erase({(*lb).second, (*lb).first}), hc.erase(lb++);
			y -= a;
		}
		else if(c == 'L'){
			auto lb = hr.lower_bound({y, x-a});
			while(lb != hr.end() and (*lb).second <= x and (*lb).first == y) ans++, hc.erase({(*lb).second, (*lb).first}), hr.erase(lb++);
			x -= a;
		}
		else if(c == 'R'){
			auto lb = hr.lower_bound({y, x});
			while(lb != hr.end() and (*lb).second <= x+a and (*lb).first == y) ans++, hc.erase({(*lb).second, (*lb).first}), hr.erase(lb++);
			x += a;
		}
	}
	cout << x << ' ' << y << ' ' << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
