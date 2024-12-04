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
	int n, k; cin >> n >> k;
	vector<int> v(n);
	string s; cin >> s; for(int i = 0; i < n; i++) v[i] = (s[i] == '1');
	
	vector<int> pref(n); pref[0] = v[0]; for(int i = 1; i < n; i++) pref[i] = pref[i-1]+(v[i] ? 1 : -1);

	auto p = [&](int a, int b){
		return pref[b]-(a ? pref[a-1] : 0);
	};

	vector<int> sums;

	int sum = 0, ans = 1;
	for(int i = 1; i < n; i++){
		if(p(i, n-1) > 0) sums.emplace_back(p(i, n-1));
	}

	sort(sums.begin(), sums.end(), greater<int>());
	for(auto& x: sums){
		sum += x, ans++;
		if(sum >= k) break;
	}

	if(sum >= k) cout << ans << endl;
	else cout << -1 << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
