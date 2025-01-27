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
	vector<int> v(n); for(auto& x: v) cin >> x;

	int sum = 0, ma = 0;
	for(auto x: v){
		sum += x; ma = max(ma, sum);
		if(sum < 0) sum = 0;
	}

	int ans = ma;
	for(int i = 0; i < k; i++) ans = ((ans+ans)%MOD+MOD)%MOD;

	for(int i = 0; i < n; i++) ans += v[i];
	ans -= ma;
	cout << ((ans%MOD)+MOD)%MOD << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
