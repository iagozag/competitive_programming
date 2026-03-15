#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;

	int sz[3]; memset(sz, 0, sizeof sz);
	for(int i = 0; i < n; i++) sz[i%3] += b[i];

	int ans[3]; memset(ans, 0, sizeof ans);
	for(int i = 0; i < n; i++){
		if(i%3 == 0){
			ans[0] += a[i]*sz[1];
			ans[1] += a[i]*sz[2];
			ans[2] += a[i]*sz[0];
		} else if(i%3 == 1){
			ans[0] += a[i]*sz[0];
			ans[1] += a[i]*sz[1];
			ans[2] += a[i]*sz[2];
		} else{
			ans[0] += a[i]*sz[2];
			ans[1] += a[i]*sz[0];
			ans[2] += a[i]*sz[1];
		}
	}

	for(int i = 0; i < 3; i++) cout << ans[i] << " \n"[i==2];
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


