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

vl a;
vector<vi> g;

bool dfs(int v, ll w){
    ll now = a[v]-w;
    if(!sz(g[v])) return now >= 0LL;

    if(now < -1e9) return false;

    bool can = true;
    forr(ve, g[v]) can &= dfs(ve, w-min(now, 0LL));
    return can;
}

void solve(){
    int n; cin >> n;
    a = vl(n); forr(x, a) cin >> x;
    g = vector<vi>(n);
    rep(i, 1, n){ int v; cin >> v; --v; g[v].eb(i); }

    ll l = a[0]+1, r = 2e9, ans = a[0];
    while(l <= r){
        ll m = l+(r-l)/2;
        bool can = true;
        forr(ve, g[0]) can &= dfs(ve, m-a[0]);
        if(can) ans = m, l = m+1;
        else r = m-1;
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
