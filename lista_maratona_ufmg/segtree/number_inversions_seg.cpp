#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

ll n, q;
vl v;
vector<pair<ll, vl>> seg;

pair<ll, vl> combine(pair<ll, vl> a, pair<ll, vl> b){
    pair<ll, vl> c; c = {a.ff+b.ff, vl(40)};
    rep(i, 0, 40){
        if(!b.ss[i]) continue;
        rep(j, i+1, 40) c.ff += b.ss[i]*a.ss[j];
    }

    rep(i, 0, 40) c.ss[i] = a.ss[i]+b.ss[i]; 
    return c;
}

pair<ll, vl> build(int node, int l, int r){
    if(l == r){
        seg[node] = {0, vl(40)};
        seg[node].ss[v[l]] = 1;
        return seg[node];
    }
    int m = (l+r)>>1;
    return seg[node] = combine(build(node*2, l, m), build(node*2+1, m+1, r));
}

pair<ll, vl> update(int node, int l, int r, int idx, int val){
    if(idx < l or idx > r) return seg[node];
    if(l == r){
        seg[node].ss = vl(40);
        seg[node].ss[val] = 1;
        return seg[node];
    }
    int m = (l+r)>>1;
    return seg[node] = combine(update(node*2, l, m, idx, val), update(node*2+1, m+1, r, idx, val));
}

pair<ll, vl> query(int node, int l, int r, int ql, int qr){
    if(qr < l or ql > r) return {0, vl(40)};
    if(ql <= l and r <= qr) return seg[node];
    int m = (l+r)>>1;
    return combine(query(node*2, l, m, ql, qr), query(node*2+1, m+1, r, ql, qr));
}

void solve(){
    cin >> n >> q;
    v = vl(n), seg = vector<pair<ll, vl>>(4*n); forr(x, v) cin >> x, --x;

    build(1, 0, n-1);

    rep(i, 0, q){
        int t, x, y; cin >> t >> x >> y; --x, --y;
        if(t == 1) cout << query(1, 0, n-1, x, y).ff << endl;
        else update(1, 0, n-1, x, y);
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
