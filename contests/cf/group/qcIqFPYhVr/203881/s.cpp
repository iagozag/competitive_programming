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
	vector<int> basis;
	for(int i = 0; i < n; i++){
		int op, x; cin >> op >> x;
		if(op == 1){
			for(auto b: basis) x = min(x, x^b);
			for(auto& b: basis) b = min(b, x^b);
			if(x) basis.emplace_back(x), sort(basis.begin(), basis.end());
		} else{
			x--;
			int ans = 0, sz = basis.size();
			for(int j = 0; j < sz; j++) if(x>>j&1ll)
				ans ^= basis[j];

			cout << ans << endl;
		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

