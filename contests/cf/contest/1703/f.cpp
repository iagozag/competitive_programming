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
	vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];

	vector<int> pref(n); for(int i = 0; i < n; i++) pref[i] = (i ? pref[i-1] : 0)+(v[i] <= i);

	int ans = 0;
	for(int i = 1; i < n; i++){
		if(v[i] <= i) ans += (v[i]-2 >= 0 ? pref[v[i]-2] : 0);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
