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
ll mi;

bool good(ll m, vl v){
    vl pref(n);
    rep(i, 0, n){
        if(i > 0) pref[i] = pref[i-1];
        if(v[i] >= m) pref[i] += v[i]-m;
        else if(v[i]+pref[i] >= m) pref[i] -= m-v[i], v[i] = m;
        else return false;
    }
    return true;
}

bool good2(ll m, vl v){
    vl pref(n);
    rep(i, 0, n-1){
        if(v[i] > m+mi) v[i+1] += v[i]-(mi+m), v[i] = mi+m;
    }

    rep(i, 0, n) if(v[i] < mi) v[i] = mi;

    ll mii = LINF, maa = -LINF;
    rep(i, 0, n) ckmin(mii, v[i]), ckmax(maa, v[i]);
    return maa-mii <= m;
}

void solve(){
    cin >> n;
    vl v(n); forr(x, v) cin >> x;

    ll l = 0, r = 1e12; mi = r;
    while(l <= r){
        ll m = l+(r-l)/2;
        if(good(m, v)) mi = m, l = m+1;
        else r = m-1;
    }

    l = 0, r = 1e12; ll ans = r;
    while(l <= r){
        ll m = l+(r-l)/2;
        if(good2(m, v)) ans = m, r = m-1;
        else l = m+1;
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
