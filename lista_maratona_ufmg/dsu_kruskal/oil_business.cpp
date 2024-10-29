#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef tuple<ll, int, int, int> tp;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> id, sz;

int find(int x){
	return (id[x] == x ? x : id[x] = find(id[x]));
}

void unio(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	id[b] = a, sz[a] += sz[b];
}

void solve(){
	int n, m; ll s; cin >> n >> m >> s;
	id = vector<int>(n), sz = vector<int>(n, 1); iota(id.begin(), id.end(), 0);
	vector<tp> edges;
	for(int i = 0; i < m; i++){
		int a, b; ll w; cin >> a >> b >> w; --a, --b; edges.emplace_back(w, a, b, i);
	}
	sort(edges.begin(), edges.end(), [&](const tp& a, const tp& b){
		return get<ll>(a) > get<ll>(b);
	});

	vector<pair<ll, int>> pos;
	for(auto [w, a, b, i]: edges){
		if(find(a) != find(b)) unio(a, b);
		else pos.emplace_back(w, i);
	}
	reverse(pos.begin(), pos.end());

	vector<int> ans;
	ll sum = 0; int i = 0;
	while(i < pos.size() and sum+pos[i].first <= s) sum += pos[i].first, ans.emplace_back(pos[i].second), i++;

	cout << ans.size() << endl;
	for(auto x: ans) cout << x+1 << " ";
	cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
