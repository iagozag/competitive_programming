#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, greater<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

struct dsu {
	vector<int> id, sz;
    vector<ord_set<int>> ord;

	dsu(int n) : id(n), sz(n, 1), ord(n) {
        iota(id.begin(), id.end(), 0); 
        rep(i, 0, n) ord[i].insert(i);
    }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;

        forr(x, ord[b]) ord[a].insert(x);
	}
};

void solve(){
    int n, q; cin >> n >> q;
    
    dsu g(n);
    
    rep(i, 0, q){
        int a, b, c; cin >> a >> b >> c;
        if(a == 1){
            --b, --c;
            if(g.find(b) != g.find(c)) g.unite(b, c); 
        } else{
            --b; b = g.find(b);
            if(g.ord[b].size() < c) cout << -1 << endl;
            else cout << (*g.ord[b].find_by_order(c-1))+1 << endl;
        }
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
