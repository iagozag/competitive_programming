#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<tuple<ll, int, int>> edges;
vector<int> id, sz;

int find(int x){
    return id[x] == x ? x : id[x] = find(id[x]);
}

void unio(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b], id[b] = a;
}

ll tryy(ll x){
    id = vector<int>(n), sz = vector<int>(n, 1);
    iota(id.begin(), id.end(), 0);

    ll ma = x; 
    for(auto [w, a, b]: edges){
        if(w >= x and find(a) != find(b)) unio(a, b), ma = max(ma, w);
    }
    int p = find(0);
    for(int i = 1; i < n; i++) if(find(i) != p) return -1;
    return ma;
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; ll w; cin >> a >> b >> w; --a, --b;
        edges.emplace_back(w, a, b);
    }
    sort(edges.begin(), edges.end());
	
	ll mi = -1, ma = LINF;
	for(int i = 0; i < m; i++){
		auto [w, a, b] = edges[i];
        ll f = tryy(w);
		if(f != -1 and ma-mi > f-w) mi = w, ma = f;  
	}

    if(mi != -1) cout << "YES" << endl << ma-mi << endl;
    else cout << "NO" << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
