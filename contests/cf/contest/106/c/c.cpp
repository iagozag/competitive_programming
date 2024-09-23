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

void solve(){
    int n, m, c0, d0; cin >> n >> m >> c0 >> d0;
    vi a, b, c, d; a = b = c = d = vi(m);
    rep(i, 0, m) cin >> a[i] >> b[i] >> c[i] >> d[i];

    vector<vi> dp(n+1, vi(m+1, -INF)); dp[0][0] = 0;
    rep(i, c0, n+1) ckmax(dp[i][0], dp[i-c0][0]+d0);

    rep(j, 1, m+1) rep(i, 0, n+1) rep(k, 0, a[j-1]/b[j-1]+1)
        if(i+c[j-1]*k <= n) ckmax(dp[i+c[j-1]*k][j], dp[i][j-1]+d[j-1]*k);

    int ans = 0;
    rep(i, 0, n+1) rep(j, 0, m+1) ckmax(ans, dp[i][j]);
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
