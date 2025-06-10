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
	int n, m; cin >> n >> m;
	vector<pair<int, int>> edges(m);
	for(auto& [a, b]: edges) cin >> a >> b, --a, --b;

	vector<int> id(n), sz(n, 1); iota(id.begin(), id.end(), 0);

	auto find = [&](auto&& self, int x) -> int{
		return (id[x] == x ? x : self(self, id[x]));
	};

	set<int> st; int ma = 1;
	for(int i = 0; i < n; i++) st.insert(i);
	auto unio = [&](int a, int b) -> void{
		a = find(find, a), b = find(find, b);
		if(a == b) return;
		if(sz[a] < sz[b]) swap(a, b);
		st.erase(id[b]);
		id[b] = a, sz[a] += sz[b], ma = max(ma, sz[a]);
	};

	for(auto [a, b]: edges){
		unio(a, b);
		cout << st.size() << ' ' << ma << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
