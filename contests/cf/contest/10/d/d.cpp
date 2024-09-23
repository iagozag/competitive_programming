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

pii get(pii a, pii b){
    if(a.ff != b.ff) return a.ff > b.ff ? a : b;
    return a.ss < b.ss ? a : b;
}

void solve(){
    int n, m; cin >> n;
    vi a(n); forr(x, a) cin >> x;
    cin >> m;
    vi b(m); forr(x, b) cin >> x;

    vector<vector<pii>> dp(n+1, vector<pii>(m+1, {0, -1})); map<int, int> par;
    rep(i, 1, n+1) rep(j, 1, m+1){
        dp[i][j] = get(dp[i-1][j], dp[i][j-1]);
        if(a[i-1] == b[j-1]){
            if(a[i-1] > dp[i][j].ss) par[a[i-1]] = dp[i][j].ss, dp[i][j].ff++, dp[i][j].ss = a[i-1];
            else if(dp[i][j].ff == 1 and a[i-1] < dp[i][j].ss) dp[i][j].ss = a[i-1], par[a[i-1]] = -1;
        }
    }

    cout << dp[n][m].ff << endl;

    vi ans;
    int p = dp[n][m].ss;
    while(p != -1) ans.eb(p), p = par[p];
    reverse(all(ans));

    forr(x, ans) cout << x << " ";
    if(sz(ans)) cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
