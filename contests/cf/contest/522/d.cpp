#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5e5+1;

int seg[2 * MAX];
int n;

void build() {
	for (int i = n - 1; i; i--) seg[i] = min(seg[2*i], seg[2*i+1]);
}

int query(int a, int b) {
	int ret = INF;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret = min(ret, seg[a]);
		if (b % 2 == 0) ret = min(ret, seg[b]);
	}
	return ret;
}

void update(int p, int x) {
	seg[p += n] = x;
	while (p /= 2) seg[p] = min(seg[2*p], seg[2*p+1]);
}

void solve(){
	int q;
	cin >> n >> q;

	int a[n]; vector<int> st;
	for(int i = 0; i < n; i++) cin >> a[i], st.emplace_back(a[i]);
	sort(st.begin(), st.end()); st.erase(unique(st.begin(), st.end()), st.end());

	for(int i = 0; i < n; i++)
		a[i] = lower_bound(st.begin(), st.end(), a[i])-st.begin();

	int nxt[n], mp[n]; fill(nxt, nxt+n, -1), fill(mp, mp+n, -1);
	for(int i = n-1; i >= 0; i--){
		if(mp[a[i]] != -1) nxt[i] = mp[a[i]];
		mp[a[i]] = i;
	}

	vector<pair<int, int>> qu[n];
	for(int i = 0; i < q; i++){
		int l, r; cin >> l >> r; --l, --r;
		qu[l].emplace_back(r, i);
	}

	for(int i = 0; i < n; i++) seg[i+n] = INF;
	build();

	vector<int> ans(q, INF);
	for(int i = n-1; i >= 0; i--){
		if(nxt[i] != -1) update(nxt[i], nxt[i]-i);

		for(auto [r, idx]: qu[i]){
			ans[idx] = query(i, r);
		}
	}

	for(auto x: ans) cout << (x == INF ? -1 : x) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
