#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<int> sz, id;

int find(int x){ return id[x] = (id[x] == x ? x : find(id[x])); }

void unite(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b], id[b] = a;
}

void solve(){
	int n, a, b; cin >> n >> a >> b;
	sz = vector<int>(n, 1), id = vector<int>(n); iota(id.begin(), id.end(), 0);

	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++){ int x; cin >> x; v[i] = {x, i}; }

	set<pair<int, int>> need; for(int i = 0; i < n; i++) need.insert(v[i]);

	for(int i = 0; i < n; i++) if(need.count(v[i])){
		queue<pair<int, int>> q; q.push(v[i]); need.erase(v[i]);
		while(!q.empty()){
			auto x = q.front(); q.pop();

			pair<int, int> l = {x.first-b, x.first-a}, r = {x.first+a, x.first+b};

			while(true){
				auto lb = need.lower_bound({l.first, 0});
				if(lb == need.end() or (*lb).first < l.first or (*lb).first > l.second) break;
				unite(x.second, (*lb).second), q.push(*lb), need.erase(lb);
			}
			while(true){
				auto lb = need.lower_bound({r.first, 0});
				if(lb == need.end() or (*lb).first < r.first or (*lb).first > r.second) break;
				unite(x.second, (*lb).second), q.push(*lb), need.erase(lb);
			}
		}
	}

	for(int i = 0; i < n; i++) cout << sz[find(i)] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

