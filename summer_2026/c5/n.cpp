#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;

	int ans = 0, m = 1, lg = log2(n);
	for(int k = 0; k < lg; k++){
		for(int i = 0; i < n; i += m*2){
			if(abs(v[i]-v[i+m]) != m){ cout << -1 << endl; return; }
			if(v[i] > v[i+m]){
				for(int j = 0; j < m; j++) swap(v[i+j], v[i+m+j]);
				ans++;
			}
		}
		m *= 2;
	}

	cout << ans << endl;
}

int32_t main(){
	int ttt = 1; cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


