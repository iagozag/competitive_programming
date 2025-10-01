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
	vector<int> v(n); for(auto& x: v) cin >> x, x %= 3;

	for(int l = 0; l < n-2; l++) for(int r = l+1; r < n-1; r++){
		vector<int> sum(3);
		for(int k = 0; k < n; k++){
			if(k <= l) sum[0] = (sum[0]+v[k])%3;
			else if(k <= r) sum[1] = (sum[1]+v[k])%3;
			else sum[2] = (sum[2]+v[k])%3;
		}

		if((sum[0] == sum[1] and sum[0] == sum[2]) or (sum[0] != sum[1] and sum[0] != sum[2] and sum[1] != sum[2])){ 
			cout << l+1 << ' ' << r+1 << endl; return; 
		}
	}

	cout << 0 << ' ' << 0 << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
