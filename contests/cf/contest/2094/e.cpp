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
	vector<int> bit(32);
	vector<int> v(n); for(auto& x: v){
		cin >> x;
		for(int i = 0; i <= 30; i++) if(x&(1LL<<i)) bit[i]++;
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < 31; j++){
			if(v[i]&(1LL<<j)) sum += (n-bit[j])*(1LL<<j);
			else sum += bit[j]*(1LL<<j);
		}

		ans = max(ans, sum);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
