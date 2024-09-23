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

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 1e8+10, MOD = 1e9+7;

int n;
vl v, seg;
vector<pair<ll, int>> lz;

ll sum_range(ll l, ll r){
    r += l, l--;
    return r*(r+1)/2-l*(l+1)/2;
}

ll build(int p, int l, int r){
    if(l == r) return seg[p] = v[l];
    int m = (l+r)>>1;
    return seg[p] = build(p<<1, l, m)+build((p<<1)+1, m+1, r);
}

void push(int p, int l, int r){
    int m = (l+r)/2;
    seg[p<<1] = sum_range(lz[p].ff+l-lz[p].ss, m-l), seg[(p<<1)+1] = sum_range(lz[p].ff+(m+1)-lz[p].ss, r-(m+1));
    lz[p<<1] = lz[(p<<1)+1] = lz[p];
    lz[p] = {-1, 0};
}

ll update(int p, int l, int r, int ul, int ur, ll val){
    if(l != r and lz[p].ff != -1) push(p, l, r);
    if(ul > r or ur < l) return seg[p];
    if(ul <= l and r <= ur){
        seg[p] = sum_range(val+l-ul, r-l), lz[p] = {val, ul};
        return seg[p];
    }
    int m = (l+r)>>1;
    return seg[p] = update(p<<1, l, m, ul, ur, val)+update((p<<1)+1, m+1, r, ul, ur, val);
}

ll query(int p, int l, int r, int ql, int qr){
    if(l != r and lz[p].ff != -1) push(p, l, r);
    if(ql > r or qr < l) return 0;
    if(ql <= l and r <= qr) return seg[p];
    int m = (l+r)>>1;
    return query(p<<1, l, m, ql, qr)+query((p<<1)+1, m+1, r, ql, qr);
}

void solve(){
    cin >> n;
    v = vl(n), seg = vl(4*n); lz = vector<pair<ll, int>>(4*n, {-1, 0});
    rep(i, 0, n){ cin >> v[i], v[i] += MAX; }

    build(1, 0, n-1);

    int q; cin >> q; ll ans = 0;
    rep(i, 0, q){
        int a; ll b; cin >> a >> b; --a, b += MAX;

        ll nowa = query(1, 0, n-1, a, a);

        if(b < nowa){
            int l = -1, r = a, idx = l;
            while(l <= r){
                int m = l+(r-l)/2;
                if(query(1, 0, n-1, m, m) < b-(a-m)) idx = m, l = m+1;
                else r = m-1;
            }
            idx++;

            ans += sum_range(nowa-b, a-idx) - abs(query(1, 0, n-1, idx, a)-(a-idx+1)*nowa);
            update(1, 0, n-1, idx, a, b-(a-idx));
        } else{
            int l = a, r = n, idx = r;
            while(l <= r){
                int m = l+(r-l)/2;
                if(query(1, 0, n-1, m, m) > b+m-a) idx = m, r = m-1;
                else l = m+1;
            }
            idx--;

            ans += sum_range(b-nowa, idx-a) - (query(1, 0, n-1, a, idx)-(idx-a+1)*nowa);
            update(1, 0, n-1, a, idx, b);
        }
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
