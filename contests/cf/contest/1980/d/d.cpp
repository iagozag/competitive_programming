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

void solve(){
    int n; cin >> n;
    vi a(n); forr(x, a) cin >> x;
    vi g(n-1);
    rep(i, 0, n-1) g[i] = __gcd(a[i], a[i+1]);

    int idx = -1;
    rep(i, 0, n-2){
        if(g[i] <= g[i+1]) continue;
        idx = i; break;
    }

    if(idx == -1) return yes();

    vi c, d, e;
    rep(i, 0, n){
        if(i == idx) continue;
        c.eb(a[i]);
    }
    idx++;
    rep(i, 0, n){
        if(i == idx) continue;
        d.eb(a[i]);
    }
    idx++;
    rep(i, 0, n){
        if(i == idx) continue;
        e.eb(a[i]);
    }

    g = vi(sz(c)-1);
    rep(i, 0, sz(c)-1) g[i] = __gcd(c[i], c[i+1]);
    bool ok = true;
    rep(i, 0, sz(g)-1){
        if(g[i] > g[i+1]){ ok = false; break; }
    }
    if(ok) return yes();

    rep(i, 0, sz(d)-1) g[i] = __gcd(d[i], d[i+1]);
    ok = true;
    rep(i, 0, sz(g)-1){
        if(g[i] > g[i+1]){ ok = false; break; }
    }
    if(ok) return yes();

    rep(i, 0, sz(e)-1) g[i] = __gcd(e[i], e[i+1]);
    ok = true;
    rep(i, 0, sz(g)-1){
        if(g[i] > g[i+1]){ ok = false; break; }
    }

    if(ok) return yes();
    return no();
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
