#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

namespace seg {
	ll seg[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return -1;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
};

void solve(){
	int n; cin >> n;
	int v[n], pos[n]; for(int i = 0; i < n; i++) cin >> v[i], --v[i], pos[v[i]] = i;

	seg::build(n, v);

	function<int(int,int,int)> dp = [&](int i, int l, int r) -> int{
		int idxl = (l <= i-1 ? pos[seg::query(l, i-1)] : -1), idxr = (i+1 <= r ? pos[seg::query(i+1, r)] : -1);
		int mal = (idxl != -1 ? dp(idxl, l, i-1)+abs(i-idxl) : 0), mar = (idxr != -1 ? dp(idxr, i+1, r)+abs(i-idxr) : 0);
		
		return max(mal, mar);
	};

	int idx = 0;
	for(int i = 1; i < n; i++) if(v[i] > v[idx]) idx = i;

	cout << dp(idx, 0, n-1) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
