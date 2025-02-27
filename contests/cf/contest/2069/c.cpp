#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto& x: v) cin >> x;

	int ans = 0, c = 0;

	int qnt = 0;
	for(int i = n-1; i >= 0; i--){
		if(v[i] == 3) qnt++;
		else if(v[i] == 1) ans = (((ans-qnt)%MOD)+MOD)%MOD;
	}

	for(int i = 0; i < n; i++){
		if(v[i] == 1) c = (c+1)%MOD;
		else if(v[i] == 2) c = c*2%MOD;
		else ans = (ans+c)%MOD;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
