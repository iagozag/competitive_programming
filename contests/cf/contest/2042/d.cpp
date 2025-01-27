#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> seg;
vector<tuple<int, int, int>> v;
int n;

int update(int p, int l, int r, int idx, int x){
	if(idx < l or idx > r) return seg[p];
	if(l == r) return seg[p] = x;

	int m = l+(r-l)/2;
	return seg[p] = max(update(p<<1, l, m, idx, x), update((p<<1)+1, m+1, r, idx, x));
}

int update2(int p, int l, int r, int idx, int x){
	if(idx < l or idx > r) return seg[p];
	if(l == r) return seg[p] = x;

	int m = l+(r-l)/2;
	return seg[p] = min(update2(p<<1, l, m, idx, x), update2((p<<1)+1, m+1, r, idx, x));
}

int query(int p, int l, int r, int x){
	if(l == r) return l;

	int m = l+(r-l)/2;
	if(seg[(p<<1)+1] >= x) return query((p<<1)+1, m+1, r, x);
	else if(seg[p<<1] >= x) return query(p<<1, l, m, x);

	return -1;
}

int query2(int p, int l, int r, int x){
	if(l == r) return l;

	int m = l+(r-l)/2;
	if(seg[(p<<1)+1] <= x) return query2((p<<1)+1, m+1, r, x);
	else if(seg[p<<1] <= x) return query2(p<<1, l, m, x);

	return -1;
}

void solve(){
	cin >> n;
	v = vector<tuple<int, int, int>>(n); int cnt = 0; map<pair<int, int>, int> mp;
	for(auto& [a, b, c]: v) cin >> a >> b, c = cnt++, mp[{a, b}]++;

	sort(v.begin(), v.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b){
		auto [a1, a2, a3] = a;
		auto [b1, b2, b3] = b;
		if(a1 != b1) return a1 < b1;
		return a2 > b2;
	});

	seg = vector<int>(4*n);

	vector<pair<int, int>> pa(n);

	// left
	for(int i = 0; i < n; i++){
		auto [a, b, idx] = v[i];
		int q = query(1, 0, n-1, b); 
		if(q != -1) pa[idx].first = get<0>(v[q]);

		update(1, 0, n-1, i, b);
	}

	sort(v.begin(), v.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b){
		auto [a1, a2, a3] = a;
		auto [b1, b2, b3] = b;
		if(a2 != b2) return a2 > b2;
		return a1 < b1;
	});

	seg = vector<int>(4*n, INF);

	// right
	for(int i = 0; i < n; i++){
		auto [a, b, idx] = v[i];
		int q = query2(1, 0, n-1, a); 
		if(q != -1) pa[idx].second = get<1>(v[q]);

		update2(1, 0, n-1, i, a);
	}

	vector<int> ans(n);
	for(int i = 0; i < n; i++){
		auto [a, b, idx] = v[i];
		if(pa[idx].first) ans[idx] += abs(a-pa[idx].first);
		if(pa[idx].second) ans[idx] += abs(b-pa[idx].second);

		if(mp[{a, b}] > 1) ans[idx] = 0;
	}

	for(auto x: ans) cout << x << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
