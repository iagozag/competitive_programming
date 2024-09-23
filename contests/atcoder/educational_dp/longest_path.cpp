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

int n, m;
vector<vi> g;
vi dp;

int dfs(int v){
    if(dp[v] != -1) return dp[v];
    if(!sz(g[v])) return dp[v] = 0;

    forr(ve, g[v]) ckmax(dp[v], dfs(ve)+1);
    return dp[v];
}

void solve(){
    cin >> n >> m;
    g.resize(n), dp = vi(n, -1);
    rep(i, 0, m){
        int a, b; cin >> a >> b; --a, --b;
        g[a].eb(b);
    }

    rep(i, 0, n) if(dp[i] == -1) dp[i] = dfs(i);

    int ma = 0;
    forr(x, dp) ckmax(ma, x);
    cout << ma << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
