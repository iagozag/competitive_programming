#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 4e5*32, MOD = 1e9+7, N = 1e9+10;

int n, m, k;

namespace seg{
	int seg[MAX], lazy[MAX], R[MAX], L[MAX], ptr;

	int get_l(int i){
		if(L[i] == 0) L[i] = ptr++;
		return L[i];
	}
	int get_r(int i){
		if(R[i] == 0) R[i] = ptr++;
		return R[i];
	}

	void build(){ ptr = 2; }

	void prop(int p, int l, int r){
		if(!lazy[p]) return;
		seg[p] += lazy[p];
		if(l != r) lazy[get_l(p)] += lazy[p], lazy[get_r(p)] += lazy[p];
		lazy[p] = 0;
	}

	int query(int a, int b, int p = 1, int l = 0, int r = N-1){
		prop(p, l, r);
		if(b < l or r < a) return 0;
		if(a <= l and r <= b) return seg[p];
		int m = l+(r-l)/2;
		return max(query(a, b, get_l(p), l, m), query(a, b, get_r(p), m+1, r));
	}

	int update(int a, int b, int x, int p = 1, int l = 0, int r = N-1){
		prop(p, l, r);
		if(b < l or r < a) return seg[p];
		if(a <= l and r <= b){
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		int m = l+(r-l)/2;
		return seg[p] = max(update(a, b, x, get_l(p), l, m), update(a, b, x, get_r(p), m+1, r));
	}
};

void solve(){
	cin >> n >> m >> k; k--;
	vector<pair<int, int>> v(m); for(auto& [a, b]: v) cin >> a >> b;
	sort(v.begin(), v.end());

	seg::build();

	int j = 0; int ans = 1;
	for(int i = 0; i < m; i++){
		while(j < m and v[j].first-v[i].first <= k){
			seg::update(max(0, v[j].second-k), v[j].second, 1), j++;
		}
		ans = max(ans, seg::query(0, n));
		seg::update(max(0, v[i].second-k), v[i].second, -1);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
