#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

typedef double ld;

ld dist(ld a, ld b, ld c, ld d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

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
	int n; cin >> n;
	vector<pair<ld, ld>> v(n); for(auto& [a, b]: v) cin >> a >> b;

	vector<tuple<ld, int, int>> edges;
	for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) 
		edges.emplace_back(dist(v[i].first, v[i].second, v[j].first, v[j].second), i, j);

	sort(edges.begin(), edges.end());

	id = vector<int>(n), iota(id.begin(), id.end(), 0); 
	sz = vector<int>(n, 1);

	ld ans = 0;
	for(auto [w, a, b]: edges){
		if(find(a) != find(b)) ans += w, unio(a, b);
	}

	cout << fixed << setprecision(2) << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--){ solve(); if(ttt) cout << endl; }

    exit(0);
}
