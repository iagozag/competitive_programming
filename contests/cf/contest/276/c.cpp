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
	vector<int> v(n); for(auto& x: v) cin >> x;
	sort(v.begin(), v.end());
	vector<int> diff(n+1); vector<pair<int, int>> qu;
	for(int i = 0; i < q; i++){
		int l, r; cin >> l >> r; --l, --r; qu.emplace_back(l, r);
		diff[l]++, diff[r+1]--;
	}
	for(int i = 1; i < n; i++) diff[i] += diff[i-1];

	set<pair<int, int>> st;
	for(int i = 0; i < n; i++) st.insert({diff[i], i});

	vector<int> nv(n); int j = 0;
	for(auto [a, b]: st) nv[b] = v[j++];

	v = nv; 
	
	int ans = 0; vector<int> pref(n);
	for(int i = 0; i < n; i++) pref[i] = (i ? pref[i-1] : 0) + v[i];
	for(auto [a, b]: qu) ans += pref[b]-(a ? pref[a-1] : 0);

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
