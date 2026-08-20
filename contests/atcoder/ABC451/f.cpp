#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int ans = 0; bool can = 1;
vector<int> id, sz, col, qnt;

int find(int x){
	if(id[x] == x) return x;
	int p = id[x];
	id[x] = find(p);
	col[x] ^= col[p];
	return id[x];
}

void unite(int a, int b){
	int pa = find(a), pb = find(b);
	bool change = col[a] == col[b];
	if(pa == pb){
		if(change) can = 0;
		return;
	}

	a = pa, b = pb;

	if(sz[a] < sz[b]) swap(a, b);

	ans -= min(qnt[a], sz[a]-qnt[a]);
    ans -= min(qnt[b], sz[b]-qnt[b]);

	if(change){
		col[b] = 1, qnt[b] = sz[b]-qnt[b];
	}

	sz[a] += sz[b], id[b] = a, qnt[a] += qnt[b];

	ans += min(qnt[a], sz[a]-qnt[a]);
}

void solve(){
	int n, q; cin >> n >> q;
	id = col = qnt = vector<int>(n); iota(id.begin(), id.end(), 0);
	sz = vector<int>(n, 1);

	for(int i = 0; i < q; i++){
		int a, b; cin >> a >> b; --a, --b;
		unite(a, b);
		if(can) cout << ans << endl;
		else cout << -1 << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
