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
	int n, l, r; cin >> n >> l >> r; --l, --r;
	vector<int> basis;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		for(auto b: basis) x = min(x, x^b);
		for(auto& b: basis) b = min(b, x^b);
		if(x) basis.emplace_back(x);
	}
	int sz = basis.size();
	sort(basis.begin(), basis.end());

	for(int i = l; i <= r; i++){
		int ans = 0;
		for(int j = 0; j < sz; j++) if(i>>j&1ll){
			ans ^= basis[j];
		}
		cout << ans << ' ';
	}

	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
