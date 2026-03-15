#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int MAX = 2e5+10, LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
int bit[MAX];

void update(int i, int x){
	for(i++; i <= n; i += i & -i) bit[i] += x;
}

int pref(int i){
	int ans = 0;
	for(i++; i; i -= i& -i) ans += bit[i];
	return ans;
}

int query(int l, int r){
	return pref(r)-pref(l-1);
}

void solve(){
	int q; cin >> n >> q;
	for(int i = 0; i < n; i++){ int x; cin >> x; update(i, x); }
	

	for(int i = 0; i < q; i++){
		int op; cin >> op;
		if(op == 1){
			int k, x; cin >> k >> x; --k;
			update(k, x-query(k, k));
		} else{
			int l, r; cin >> l >> r; --l, --r;
			cout << query(l, r) << endl;
		}
	}
}

int32_t main(){
	int ttt = 1; // cin >> ttt;
	while(ttt--) solve();

	exit(0);
}

