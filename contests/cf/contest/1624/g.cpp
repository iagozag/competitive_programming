#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> id, sz;

int find(int x){
	return id[x] = (id[x] == x ? x : find(id[x]));
}

void unio(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b], id[b] = a;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<tuple<int, int, int>> edges(m);
	for(auto& [a, b, w]: edges) cin >> a >> b >> w, --a, --b;

	auto good = [&](int x) -> bool{
		id = vector<int>(n), sz = vector<int>(n, 1);
		iota(id.begin(), id.end(), 0);

		for(auto [a, b, w]: edges) if((w&x) == w) unio(a, b);

		return sz[find(0)] == n;
	};

	int ans = (1ll<<31)-1;
	for(int i = 30; i >= 0; i--){
		if(good(ans^(1ll<<i))) ans ^= (1<<i);
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
