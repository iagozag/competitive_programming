#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9;

void solve(){
	int n, k; cin >> n >> k; n++;
	
	if(n <= k){ cout << 1 << endl; return; }

	vector<int> pref(n);
	vector<int> v(n); for(int i = 0; i < k; i++) v[i] = 1, pref[i] = (i ? pref[i-1] : 0)+v[i];

	for(int i = k; i < n; i++){
		v[i] = pref[i-1]-(i-k-1 >= 0 ? pref[i-k-1] : 0), v[i] %= MOD, v[i] += MOD, v[i] %= MOD;
		pref[i] = pref[i-1]+v[i], pref[i] %= MOD, pref[i] += MOD, pref[i] %= MOD;
	}

	cout << v[n-1]%MOD << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
