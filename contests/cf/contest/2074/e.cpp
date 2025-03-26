#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int query(int i, int j, int k){
	cout << "? " << i << ' ' << j << ' ' << k << ' ' << endl;
	int q; cin >> q; return q;
}

void solve(){
	int n; cin >> n;
	int x[3] = {1, 2, 3};
	while(1){
		int q = query(x[0], x[1], x[2]);
		if(!q) break;
		x[uniform(0, 2)] = q;
	}
	cout << "! " << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
}

int32_t main(){
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
