#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void no(){
	cout << -1 << endl;
}

ll sum(ll a, ll b){
	return a*(a+1)/2LL-b*(b+1)/2LL;
}

void solve(){
	ll n, m; cin >> n >> m;
	vector<pair<ll, ll>> v(m);
	for(int i = 0; i < m; i++) cin >> v[i].first;
	for(int i = 0; i < m; i++) cin >> v[i].second;
	sort(v.begin(), v.end());
	if(v[m-1].first != n) v.emplace_back(n, 0);

	ll ans = 0;
	for(int i = 1; i < v.size(); i++){
		ll need = (v[i].second == 0)+(v[i].first-v[i-1].first)-1;
		ll qnt = v[i-1].second-1;
		if(qnt < need) return no();

		ans += sum(qnt, qnt-(v[i].first-v[i-1].first));
		v[i].second += qnt-need;
	}

	if(v.back().second > 1) return no();
	else cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
