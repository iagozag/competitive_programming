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
	vector<int> v(n); for(auto& x: v) cin >> x;

	int ans = LINF;
	for(int i = 0; i < n; i++){
		int mi = LINF, ma = -LINF;
		for(int j = i-1; j >= 0; j--){
			mi = min(mi, v[j]);
			ma = max(ma, v[j]);
			if(mi <= v[i]+1 and ma >= v[i]-1) ans = min(ans, i-j-1);
		}

		mi = LINF, ma = -LINF;
		for(int j = i+1; j < n; j++){
			mi = min(mi, v[j]);
			ma = max(ma, v[j]);
			if(mi <= v[i]+1 and ma >= v[i]-1) ans = min(ans, j-i-1);
		}
	}

	cout << (ans == LINF ? -1 : ans) << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
