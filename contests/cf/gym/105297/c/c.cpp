#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

int n, q;
vl b, c, pref, seg, lz;

ll build(int node, int l, int r){
    if(l == r) return seg[node] = pref[l];
    int m = l+(r-l)/2;
    return seg[node] = min(build(node<<1, l, m), build((node<<1)+1, m+1, r));
}

void push(int node, int l, int r){
    if(l == r or !lz[node]) return;

    seg[node<<1] += lz[node];
    lz[node<<1] += lz[node];
    seg[(node<<1)+1] += lz[node];
    lz[(node<<1)+1] += lz[node];
    lz[node] = 0;
}

ll update(int node, int l, int r, int ul, int ur, int x){
    push(node, l, r);
    if(ul > r or ur < l) return seg[node];
    if(ul <= l and r <= ur){
        seg[node] += x, lz[node] += x;
        return seg[node];
    }
    int m = l+(r-l)/2;
    return seg[node] = min(update(node<<1, l, m, ul, ur, x), update((node<<1)+1, m+1, r, ul, ur, x));
}

int query(int node, int l, int r, int ql, int qr, ll x){
    push(node, l, r);
    if(l > qr or r < ql or seg[node]-x >= 0) return -1;
    if(l == r) return l;

    int m = l+(r-l)/2, ans = -1;
    ans = query(node<<1, l, m, ql, qr, x);
    if(ans == -1) ans = query((node<<1)+1, m+1, r, ql, qr, x);
    return ans;
}

ll getnode(int node, int l, int r, int idx){
    push(node, l, r);
    if(l == r) return seg[node];
    int m = l+(r-l)/2;
    if(idx <= m) return getnode(node<<1, l, m, idx);
    return getnode((node<<1)+1, m+1, r, idx);
}

void solve(){
    cin >> n >> q;
    b = c = pref = vl(2*n), seg = lz = vl(8*n);
    rep(i, 0, n){ cin >> b[i]; b[i+n] = b[i]; }
    rep(i, 0, n){ cin >> c[i]; c[i+n] = c[i]; }

    pref[0] = b[0]-c[0];
    rep(i, 1, 2*n) pref[i] = pref[i-1]+(b[i]-c[i]); 

    build(1, 0, 2*n-1);

    rep(i, 0, q){
        int op, j; ll x; cin >> op >> j; --j;
        if(op == 1){
            int ans = query(1, 0, 2*n-1, j, j+n, j > 0 ? getnode(1, 0, 2*n-1, j-1) : 0);
            cout << (ans == -1 ? -1 : ans%n+1) << endl;
        }
        else{
            cin >> x;
            if(op == 2) update(1, 0, 2*n-1, j, 2*n-1, x-b[j]), 
                        update(1, 0, 2*n-1, j+n, 2*n-1, x-b[j]), 
                        b[j] = b[j+n] = x;
            else update(1, 0, 2*n-1, j, 2*n-1, c[j]-x), 
                 update(1, 0, 2*n-1, j+n, 2*n-1, c[j]-x),
                 c[j] = c[j+n] = x;
        }
    }
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
