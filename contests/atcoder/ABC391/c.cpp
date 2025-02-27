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
	int n, q; cin >> n >> q;
	vector<int> idx(n), nest(n, 1);
	iota(idx.begin(), idx.end(), 0);

	int ans = 0;
	for(int i = 0; i < q; i++){
		int op; cin >> op;
		if(op == 1){
			int p, h; cin >> p >> h; --p, --h;
			if(nest[idx[p]] == 2) ans--;
			if(nest[h] == 1) ans++;
			nest[idx[p]]--, nest[h]++, idx[p] = h;
		} else cout << ans << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
