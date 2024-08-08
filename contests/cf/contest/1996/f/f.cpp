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

void solve(){
    ll n, k, ma = 0; cin >> n >> k;
    vl a(n), b(n); forr(x, a) cin >> x, ckmax(ma, x); forr(x, b) cin >> x;

    ll l = 0, r = ma, x = 0;
    while(l <= r){
        ll m = l+(r-l)/2;
        ll tot = 0;
        rep(i, 0, n){
            if(a[i] < m) continue;
            tot += max((a[i]-m)/b[i]+1LL, 0LL);
        }

        if(tot >= k) x = m, l = m+1;
        else r = m-1;
    }

    ll ans = 0, tot = 0; x++;
    rep(i, 0, n){
        if(a[i] < x) continue;
        ll qnt = max((a[i]-x)/b[i]+1LL, 0LL);
        ans += a[i]*qnt-b[i]*qnt*(qnt-1)/2, tot += qnt;
    }

    k -= tot; x--;
    ans += k*x;

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
