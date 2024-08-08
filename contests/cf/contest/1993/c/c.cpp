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

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "-1" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

vl v, seg, lz;

void push(int node, int l, int r){
    if(lz[node] and l != r){
        seg[node<<1] += lz[node], seg[(node<<1)+1] += lz[node];
        lz[node<<1] += lz[node], lz[(node<<1)+1] += lz[node];
        lz[node] = 0;
    }
}

ll update(int node, int l, int r, int ul, int ur){
    push(node, l, r);
    if(ul > r or ur < l) return seg[node];
    if(ul <= l and r <= ur){
        seg[node]++, lz[node]++;
        return seg[node];
    }
    int m = l+(r-l)/2;
    return seg[node] = max(update(node<<1, l, m, ul, ur), update((node<<1)+1, m+1, r, ul, ur));
}

ll query(int node, int l, int r, int ql, int qr){
    push(node, l, r);
    if(ql > r or qr < l) return -1;
    if(ql <= l and r <= qr) return seg[node];
    int m = l+(r-l)/2;
    return max(query(node<<1, l, m, ql, qr), query((node<<1)+1, m+1, r, ql, qr));
}

void solve(){
    ll n, k, mx = -1; cin >> n >> k;
    v = vl(n), seg = lz = vl(8*k); forr(x, v) cin >> x, ckmax(mx, x), x %= (k<<1);

    rep(i, 0, n){
        int l = v[i], r = (v[i]+k-1)%(k<<1);
        if(l <= r) update(1, 0, 2*k-1, l, r); 
        else update(1, 0, 2*k-1, l, 2*k-1), update(1, 0, 2*k-1, 0, r);
    }

    if(query(1, 0, 2*k-1, 0, 2*k-1) != n) return no();

    while(query(1, 0, 2*k-1, mx%(k<<1), mx%(k<<1)) != n) mx++;
    cout << mx << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
