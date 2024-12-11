#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> id(MAX), sz(MAX, 1);

int find(int x){
	return (id[x] == x ? x : id[x] = find(id[x]));
}

void unite(int x, int y){
	if(sz[x] < sz[y]) swap(x, y);
	id[y] = x, sz[x] += sz[y];
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<tuple<int, int, int>> edges(m);
	for(auto& [a, b, c]: edges) cin >> b >> c >> a, --b, --c;
	sort(edges.begin(), edges.end());

	vector<int> a(MAX), b(MAX);
	for(int i = 0; i < k; i++){ int x; cin >> x; --x; a[x]++; }
	for(int i = 0; i < k; i++){ int y; cin >> y; --y; b[y]++; }

	iota(id.begin(), id.end(), 0);

	int ans = 0;
	for(auto [c, x, y]: edges){
		x = find(x), y = find(y);
		if(x == y) continue;

		unite(x, y);

		int mi = max(min(a[x], b[y]), min(a[y], b[x]));
		ans += mi*c;

		if(a[x]) a[x] -= mi;
		if(a[y]) a[y] -= mi;
		if(b[x]) b[x] -= mi;
		if(b[y]) b[y] -= mi;

		if(x != find(x) and a[x]) a[find(x)] += a[x], a[x] = 0;
		if(y != find(y) and a[y]) a[find(y)] += a[y], a[y] = 0;
		if(x != find(x) and b[x]) b[find(x)] += b[x], b[x] = 0;
		if(y != find(y) and b[y]) b[find(y)] += b[y], b[y] = 0;
	}
	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
