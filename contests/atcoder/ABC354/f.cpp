#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, k;

struct Seg{
	vector<int> seg;

	Seg(){
		seg = vector<int>(4*k);
	}

	int query(int a, int b, int p = 1, int l = 0, int r = k-1) {
		if(a > r or b < l) return 0;
		if(a <= l and b >= r) return seg[p];
		int m = l+(r-l)/2;
		return max(query(a, b, p<<1, l, m), query(a, b, (p<<1)+1, m+1, r));
	}

	int update(int idx, int x, int p = 1, int l = 0, int r = k-1) {
		if(idx < l or idx > r) return seg[p];
		if(l == r) return seg[p] = x;
		int m = l+(r-l)/2;
		return seg[p] = max(update(idx, x, p<<1, l, m), update(idx, x, (p<<1)+1, m+1, r));
	}
};

void solve(){
	cin >> n; set<int> st;
	vector<int> v(n); for(auto& x: v) cin >> x, st.insert(x);
	k = 0; map<int, int> mp;
	for(auto x: st) mp[x] = k++;
	for(auto& x: v) x = mp[x];

	Seg seg;

	vector<int> dp(n), dp2(n); int ma = 0;
	for(int i = 0; i < n; i++){
		dp[i] = (v[i] ? seg.query(0, v[i]-1) : 0)+1;
		seg.update(v[i], max(seg.query(v[i], v[i]), dp[i]));
		ma = max(ma, dp[i]);
	}

	seg = Seg();

	for(int i = n-1; i >= 0; i--){
		dp2[i] = (v[i]+1 <= k-1 ? seg.query(v[i]+1, k-1) : 0)+1;
		seg.update(v[i], max(seg.query(v[i], v[i]), dp2[i]));
	}

	vector<int> ans;
	for(int i = 0; i < n; i++){
		if(dp[i]+dp2[i]-1 == ma) ans.emplace_back(i+1);
	}
	
	cout << ans.size() << endl;
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
