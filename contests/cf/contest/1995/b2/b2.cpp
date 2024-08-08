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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

ll comb(ll a, ll ca, ll b, ll cb, ll m){
    ll ma = min(m-(m%a), a*ca), useda = ma/a; ca -= useda;
    ll rest = (m-ma)/b;
    ma += b*(min(rest, cb)), cb -= min(rest, cb);

    ll diff = m-ma;
    ma += min({diff, cb, useda});

    return ma;
}

void solve(){
    ll n, m; cin >> n >> m;
    vl a(n), c(n);
    forr(x, a) cin >> x;
    forr(x, c) cin >> x;
    vector<pll> v(n);
    rep(i, 0, n) v[i] = {a[i], c[i]};
    sort(all(v));

    ll ma = 0;
    rep(i, 0, n){
        if(v[i].ff > m) break;
        ckmax(ma, min(m-(m%v[i].ff), v[i].ff*v[i].ss));
        if(i > 0 and v[i].ff-v[i-1].ff == 1) ckmax(ma, comb(v[i-1].ff, v[i-1].ss, v[i].ff, v[i].ss, m));
    }

    cout << ma << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
