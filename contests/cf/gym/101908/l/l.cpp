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

const int MAX = 1e5+10, MOD = 1e9+7;

namespace seg{
    ll seg[4*MAX], lazy[4*MAX];
    int n, *v;

    ll build(int p=1, int l=0, int r=n-1){
        lazy[p] = 0;
        if(l == r) return seg[p] = v[l];
        int m = (l+r)>>1;
        return seg[p] = build(2*p, l, m)+build(2*p+1, m+1, r);
    }

    void build(int n2, int* v2){
        n = n2, v = v2;
        build();
    }
    void prop(int p, int l, int r){
        seg[p] += lazy[p]*(r-l+1);
        if(l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
        lazy[p] = 0;
    }
    ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m)+query(a, b, 2*p+1, m+1, r);
	}
    ll update(int a, int b, int x, int p=1, int l=0, int r=n-1){
        prop(p, l, r);
        if(a <= l and r <= b){
            lazy[p] += x;
            prop(p, l, r);
            return seg[p];
        }
        if(b < l or r < a) return seg[p];
        int m = (l+r)>>1;
        return seg[p] = update(a, b, x, 2*p, l, m)+update(a, b, x, 2*p+1, m+1, r);
    }
};

namespace hld{
    vector<int> g[MAX];
    int pos[MAX], sz[MAX];
    int peso[MAX], pai[MAX];
    int h[MAX], v[MAX], t;

    void build_hld(int k, int p = -1, int f = 1){
        v[pos[k] = t++] = peso[k]; sz[k] = 1;
        forr(i, g[k]) if(i != p){
            pai[i] = k;
            h[i] = (i == g[k][0] ? h[k] : i);
            build_hld(i, k, f); sz[k] += sz[i];

            if(sz[i] > sz[g[k][0]] or g[k][0] == p) swap(i, g[k][0]);
        }
        if(p*f == -1) build_hld(h[k] = k, -1, t = 0);
    }
    void build(int root = 0){
        t = 0;
        build_hld(root);
        seg::build(t, v);
    }
    ll query_path(int a, int b){
        if(pos[a] < pos[b]) swap(a, b);

        if(h[a] == h[b]) return seg::query(pos[b], pos[a]);
        return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
    }
    void update_path(int a, int b, int x){
        if(pos[a] < pos[b]) swap(a, b);

        if(h[a] == h[b]) return (void)seg::update(pos[b], pos[a], x);
        seg::update(pos[h[a]], pos[a], x), update_path(pai[h[a]], b, x);
    }
    ll query_subtree(int a){
        return seg::query(pos[a], pos[a]+sz[a]-1);
    }
    void update_subtree(int a, int x){
        seg::update(pos[a], pos[a]+sz[a]-1, x);
    }
    int lca(int a, int b){
        if(pos[a] < pos[b]) swap(a, b);
        return h[a] == h[b] ? b : lca(pai[h[a]], b);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    rep(i, 0, n-1){
        int a, b; cin >> a >> b; --a, --b;
        hld::g[a].eb(b), hld::g[b].eb(a);
    }

    hld::build();

    rep(i, 0, q){
        int a, b, c, d; cin >> a >> b >> c >> d; --a, --b, --c, --d;
        hld::update_path(a, b, 1);
        cout << hld::query_path(c, d) << endl;
        hld::update_path(a, b, -1);
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
