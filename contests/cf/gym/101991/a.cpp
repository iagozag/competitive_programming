#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

namespace seg{
	int seg[2 * MAX];
	int n;

	void build() {
		for (int i = n - 1; i; i--) seg[i] = seg[2*i] + seg[2*i+1];
	}

	int query(int a, int b) {
		int ret = 0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret += seg[a];
			if (b % 2 == 0) ret += seg[b];
		}
		return ret;
	}

	void update(int p, int x) {
		seg[p += n] += x;
		while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
	}
}

int n, L, R;

vector<int> g[MAX];
int sz[MAX], rem[MAX];

void dfs(vector<int>& path, int i, int l=-1, int d=0) {
	path.push_back(d);
	for (int j : g[i]) if (j != l and !rem[j]) dfs(path, j, i, d+1);
}

int dfs_sz(int i, int l=-1) {
	sz[i] = 1;
	for (int j : g[i]) if (j != l and !rem[j]) sz[i] += dfs_sz(j, i);
	return sz[i];
}

int centroid(int i, int l, int size) {
	for (int j : g[i]) if (j != l and !rem[j] and sz[j] > size / 2)
		return centroid(j, i, size);
	return i;
}

ll decomp(int i, int needl, int needr) {
	int c = centroid(i, i, dfs_sz(i));
	rem[c] = 1;

	ll ans = 0;

	seg::n = sz[i];
	for(int j = 0; j < sz[i]; j++) seg::seg[j+sz[i]] = 0;
	seg::build();

	seg::update(0, 1);
	for (int j : g[c]) if (!rem[j]) {
		vector<int> path;
		dfs(path, j);

		for (int d : path){
			int l = max(0ll, needl-d-1), r = min(sz[i]-1, needr-d-1);
			if(l <= r) ans += seg::query(l, r);
		}

		for (int d : path) seg::update(d+1, 1);
	}

	for (int j : g[c]) if (!rem[j]) ans += decomp(j, needl, needr);
	rem[c] = 0;
	return ans;
}

void solve(){
	cin >> n >> L >> R;

	for(int i = 0; i < n; i++){
		sz[i] = 0, rem[i] = 0, g[i].clear();
	}

	for(int i = 0; i < n-1; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }

	int needl = n-R-1, needr = n-L-1;
	cout << decomp(0, needl, needr) << endl;

}

int32_t main(){ _
    if (fopen("awesome.in", "r")) {
		freopen("awesome.in", "r", stdin);
	}

    int ttt = 1; cin >> ttt;

	memset(seg::seg, 0, sizeof seg::seg);
	memset(sz, 0, sizeof sz);
	memset(rem, 0, sizeof rem);

    while(ttt--) solve();

    exit(0);
}
