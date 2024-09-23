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

const int MAX = 4e5+10, MOD = 1e9+7;

vi seg;

int update(int p, int l, int r, int idx, int x){
    if(idx < l or idx > r) return seg[p];
    if(l == r) return seg[p] += x;
    int m = l+(r-l)/2;
    return seg[p] = max(update(p<<1, l, m, idx, x), update((p<<1)+1, m+1, r, idx, x));
}

void solve(){
    int n, k, q; cin >> n >> k >> q;
    vi v(n); rep(i, 0, n){ int a; cin >> a; v[i] = a-i+2e5; }

    vi ans(n-k+1);
    rep(i, 0, k) update(1, 0, MAX-1, v[i], 1);
    rep(i, 0, n-k+1){
        ans[i] = seg[1];
        if(i+k < n) update(1, 0, MAX-1, v[i], -1), update(1, 0, MAX-1, v[i+k], 1);
    }

    rep(i, n-k, n) update(1, 0, MAX-1, v[i], -1);

    rep(i, 0, q){
        int a, b; cin >> a >> b; --a, --b;
        cout << k-ans[a] << endl; 
    }
}

int main(){ _
    int ttt = 1; cin >> ttt;

    seg = vi(4*MAX);

    while(ttt--) solve();

    exit(0);
}
