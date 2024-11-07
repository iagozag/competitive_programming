#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, k; cin >> k >> n;
	map<int, ll, greater<int>> mp;
	for(int i  = 0; i < n; i++){
		int a, b; cin >> a >> b; --a;
		mp[a] += b;
	}
	
	vector<ll> v;
	for(auto x: mp) v.emplace_back(x.second);

	sort(v.begin(), v.end(), greater<ll>());

	ll ans = 0;
	for(int i = 0; i < (int)min((int)v.size(), k); i++) ans += v[i];
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
