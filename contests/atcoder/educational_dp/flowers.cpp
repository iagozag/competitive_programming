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

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vl h, a, seg;

ll update(int p, int l, int r, int idx, ll v){
    if(idx < l or idx > r) return seg[p];
    if(l == r) return seg[p] = v;
    int m = (l+r)/2;
    return seg[p] = max(update(p<<1, l, m, idx, v), update((p<<1)+1, m+1, r, idx, v));
}

ll query(int p, int l, int r, int ql, int qr){
    if(ql > r or qr < l) return 0;
    if(ql <= l and r <= qr) return seg[p];
    int m = (l+r)/2;
    return max(query(p<<1, l, m, ql, qr), query((p<<1)+1, m+1, r, ql, qr));
}

void solve(){
    cin >> n;
    h = a = vl(n), seg = vl(4*MAX); forr(x, h) cin >> x; forr(x, a) cin >> x;

    vl dp(n+1);
    rep(i, 0, n){
        dp[h[i]] = a[i]+query(1, 0, MAX-1, 1, h[i]-1);
        update(1, 0, MAX-1, h[i], dp[h[i]]);
    }

    cout << seg[1] << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
