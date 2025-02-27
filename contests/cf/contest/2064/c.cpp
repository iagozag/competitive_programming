#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<int> v, pref;

int get_sum(int l, int r){
	if(l > r) return 0;
	return pref[r] - (l ? pref[l-1] : 0);
}

void solve(){
	cin >> n;
	v = pref = vector<int>(n); for(auto& x: v) cin >> x;

	pref[0] = (v[0] < 0 ? -v[0] : 0);
	for(int i = 1; i < n; i++) pref[i] = pref[i-1] - (v[i] < 0 ? v[i] : 0);

	int ma = 0, tot = 0;
	for(int i = 0; i < n; i++){
		if(v[i] > 0){
			tot += v[i], ma = max(ma, tot+get_sum(i+1, n-1));
		}
	}
	cout << max({ma, tot, pref[n-1]}) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
